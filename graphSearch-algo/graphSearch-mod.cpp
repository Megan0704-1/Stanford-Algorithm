#include <bits/stdc++.h>

#define min(_a, _b) \
    ((_a)<(_b) ? (_a) : (_b))

using namespace std;

static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second > p2.second;
}

class Solution {
    string _filename;
    int time = 1;
    unordered_map<int, vector<int>> _graph;
    unordered_map<int, vector<int>> _reverse_graph;
    unordered_map<int, bool> visited;
    vector<pair<int, int>> finishTime;
    vector<int> res;

    int bs(vector<int> &arr, int val) {
        int left{}, right{(int)arr.size()};
        while(left < right) {
            int mid = left + (right - left)/2;
            if(arr[mid] < val)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
    void getGraph() {
        ifstream f;
        f.open(_filename);
        int vertex, node;
        while(f >> vertex >> node) {
            _graph[vertex].push_back(node);
        }
        f.close();
    }

    void getReverseGraph() {
        for(auto I=_graph.begin(), E=_graph.end(); I!=E; ++I) {
            for(int n: I->second) {
                _reverse_graph[n].push_back(I->first);
            }
        }
    }

    void getResult() {
        visited.clear();
        for(auto I: finishTime) {
            if(visited[I.first])
                continue;
            int cnt = 0;
            dfs(I.first, cnt, _reverse_graph);
            int pos = bs(res, cnt);
            res.insert(res.begin() + pos, cnt);
            if(res.size() > 5)
                res.pop_back();
        }
    }

    void dfs(int node, int &cnt, unordered_map<int, vector<int>> &g, bool setFinish=false) {
        if(visited[node])
            return;
        visited[node] = 1;
        cnt++;
        for(int neighbor: g[node]) {
            if(!visited[neighbor])
                dfs(neighbor, cnt, g, setFinish);
        }
        if(setFinish)
            finishTime.push_back({node, time++});
    }

    void getFinishTime() {
        for(auto I=_graph.begin(), E=_graph.end(); I!=E; ++I) {
            if(visited.find(I->first) != visited.end())
                continue;
            int cnt = 0;
            dfs(I->first, cnt, _graph, true);
        }
        sort(finishTime.begin(), finishTime.end(), cmp);
    }

    void printResult() {
        int rem = 5 - res.size();
        for(int i=0; i<res.size(); ++i)
            cout << res[i] << ',';
        for(int i=0; i < rem; ++i)
            cout << "0,";
        cout << "\b";
    }

public:
    Solution(string filename): _filename(filename) {}

    void run() {
        getGraph();
        getFinishTime();
        getReverseGraph();
        getResult();
        printResult();
    }
};

int main(int argc, char *argv[]) {
    string filename = "assignment3.txt";
    // string filename = "test.txt";
    Solution sol(filename);
    sol.run();
    return 0;
}
