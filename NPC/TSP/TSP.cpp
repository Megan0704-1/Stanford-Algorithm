#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using std::cout;
using std::cin;

class Algorithm{
public:
    double ans = INT8_MAX;
    std::string path;
    int ncities;
    std::vector<std::pair<double, double>> location;
    std::vector<std::vector<double>> C;
    std::vector<std::vector<double>> A;

    void read_file();
    void compute_len();
    void run_algo();
    int dp(int, int);

    Algorithm(std::string _p): path(_p){}
};

void Algorithm::read_file(){
    std::ifstream fh(path);
    fh >> ncities;
    location = std::vector<std::pair<double, double>>(ncities+1);
    C = std::vector<std::vector<double>>(ncities+1, std::vector<double>(ncities+1, 0));
    A = std::vector<std::vector<double>>((ncities+1), std::vector<double>(1<<(ncities+1), INT8_MAX));
    
    int idx=1;
    double x, y;
    while(fh >> x >> y){
        location[idx] = {x, y};
        idx++;
    }
    fh.close();
    cout << "done read.\n";
}

void Algorithm::compute_len(){
    for(int i=1; i<=ncities; i++){
        for(int j=1; j<=ncities; j++){
            std::pair<double, double> loc1 = location[i];
            std::pair<double, double> loc2 = location[j];
            C[i][j] = std::sqrt(std::pow(loc1.first-loc2.first, 2) + std::pow(loc1.second-loc2.second, 2));
            C[j][i] = C[i][j];
        }
    }

    cout << "done computing len.\n";
}

void Algorithm::run_algo(){
    A[1][1] = 0;

    for(int j=2; j<=ncities; j++){
        ans = std::min(ans, dp(j, (1<<(ncities+1))-1)+C[j][1]);
    }
}

int Algorithm::dp(int start, int vtx_comb){
    if(vtx_comb == (1<<start | 1)) return C[1][start];

    if(A[start][vtx_comb] != INT8_MAX) return A[start][vtx_comb];

    int res = INT8_MAX;
    for(int k=1; k<=ncities; k++){
        if(vtx_comb & (1<<k) && k!=start && k!=1){
            int new_state = vtx_comb & (~(1<<start));
            res = std::min(res, dp(k, new_state));
        }
    }
    A[start][vtx_comb] = res;
    return res;
}

int main(int argc, char* argv[]){
    Algorithm TSP(argv[1]);
    TSP.read_file();
    TSP.compute_len();
    TSP.run_algo();
    cout << TSP.ans << "\n";
}