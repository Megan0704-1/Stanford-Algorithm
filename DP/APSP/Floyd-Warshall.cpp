#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define cmp_min(a,b) a<b?a:b

using namespace std;

class Solution{
public:
    string path;
    int n=1001;
    int MAX = INT8_MAX;
    vector<vector<vector<int>>> A = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, MAX)));
    vector<vector<int>> C = vector<vector<int>>(n, vector<int>(n, MAX));
    vector<vector<int>> E = vector<vector<int>>(n, vector<int>(n, 0));
    void read_file();
    void run_algo();
    bool check_negative_cycle();

    Solution(string _p): path(_p){};
};

bool Solution::check_negative_cycle(){
    for(int i=1; i<=n; i++){
        if(A[i][i][n] < 0){
            cout << "Graph has negative cycle\n";
            return 0;
        }
    }
    cout << "Graph has no negative cycle\n";
    return 1;
}

void Solution::run_algo(){
    int k=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) A[i][j][k] = 0;
            else if(E[i][j]) A[i][j][k]=C[i][j];
            else A[i][j][k] = MAX;
        }
    }
    cout << "done init\n";
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                A[i][j][k] = cmp_min(A[i][j][k-1], A[i][k][k-1]+A[k][j][k-1]);
            }
        }
    }

    cout << "done run\n";

    bool check = check_negative_cycle();
    if(check){
        int min = MAX;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(A[i][j][n] < min) min = A[i][j][n];
            }
        }
        cout << "min: " << min << endl;
    }
}

void Solution::read_file(){
    ifstream fh(path);
    int edges;
    fh >> n >> edges;
    int u, v, edge;
    while(fh >> u >> v >> edge){
        C[u][v] = edge;
        E[u][v] = 1;
    }
    fh.close();
    cout << "read done\n";
}

int main(int argc, char** argv){
    Solution sol(argv[1]);
    sol.read_file();
    sol.run_algo();
    return 0;
}