#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define ull unsigned long long

using namespace std;

class Solution{
public:
    ull W; int n;
    vector<ull> value;
    vector<ull> weights;
    string path;

    Solution (string _p): 
        path(_p){}

    void read_file();
    void run(vector<vector<ull>>& a);
};

void Solution::read_file(){
    ifstream fh(path);
    fh >> W >> n;
    int v, w;

    value.push_back(0); weights.push_back(0);

    while(fh >> v >> w){
        value.push_back(v);
        weights.push_back(w);
    }
    vector<vector<ull>> A(n+1, vector<ull>(W+1, 0));

    cout << "knapstack size: " << W << ", item nun: " << n << "\n";
    cout << "value vec size: " << value.size() << ", weights vec size: " << weights.size() << "\n";

    run(A);
}

void Solution::run(vector<vector<ull>>& A){
    for(int x=0; x<=W; x++){
        A[0][x]=0;
    }

    for(int i=1; i<=n; i++){
        for(int x=0; x<=W; x++){
            if(weights[i] > x) A[i][x] = A[i-1][x];
            else A[i][x] = max(A[i-1][x], value[i]+A[i-1][x-weights[i]]);
        }
    }
    cout << "ans: " << A[n][W] << "\n";
}

int main(int argc, char* argv[]){
    Solution* sol = new Solution(argv[1]);
    sol->read_file();
    return 0;
}