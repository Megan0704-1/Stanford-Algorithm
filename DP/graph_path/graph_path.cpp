#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#define cmp_max(a,b) a>b?a:b

using namespace std;

class Solution{
public:
    vector<int> graph;
    vector<int> candidate;
    set<int> IS;
    string data_path;
    string candidate_path;

    void read_file();
    void memoziation();
    void judge();

    Solution(string _p, string _p1): 
        data_path(_p), candidate_path(_p1){
            graph.push_back(0);
        };
};

void Solution::read_file(){
    ifstream arr(data_path);
    ifstream cand(candidate_path);

    int n; arr >> n;
    int w;
    cout << "num graph: " << n << "\n";
    while(arr >> w) graph.push_back(w);
    arr.close();

    cand >> n;
    cout << "num candidate: " << n << "\n";
    int idx;
    while(cand >> idx) candidate.push_back(idx);

    cout << "graph size: " << graph.size() << ", cand size: " << candidate.size() << "\n";
}

void Solution::memoziation(){
    vector<pair<int, set<int>>> data(graph.size());
    data[0]={graph[0], {}}; data[1]={graph[1], {1}};
    for(int i=2; i<graph.size(); i++){
        int val = cmp_max(data[i-1].first, data[i-2].first+graph[i]);
        set<int> s;
        if(val==data[i-1].first) s=data[i-1].second;
        else{
            s=data[i-2].second;
            s.insert(i);
        }
        data[i]={val, s};
    }
    IS = data[graph.size()-1].second;
}

void Solution::judge(){
    for(auto &x: candidate){
        if(IS.find(x)!=IS.end()) cout << "1, ";
        else cout << "0, ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]){
    Solution* sol = new Solution(argv[1], argv[2]);
    sol->read_file();
    sol->memoziation();
    sol->judge();
    return 0;
}