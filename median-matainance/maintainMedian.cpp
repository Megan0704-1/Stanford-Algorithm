#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#define ll long long
#define v_type int

using namespace std;

class Solution{
protected:
    priority_queue<v_type> max_heap;
    priority_queue<v_type, vector<v_type>, greater<v_type>> min_heap;
    v_type medianSum=0;

public:
    void run(string filename);
};

void Solution::run(string filename){
    ifstream fh(filename);
    v_type num;
    while(fh >> num){
        if(max_heap.empty() && min_heap.empty()) max_heap.push(num);
        else if(!min_heap.empty() && num > min_heap.top()) min_heap.push(num);
        else max_heap.push(num);

        if(max_heap.size() > min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        medianSum += max_heap.top();
        medianSum %= 10000;
    }
    cout << max_heap.size() << ", " << min_heap.size() << "\n";
    cout << "ans=" << medianSum << "\n";
}

int main(){
    string path = "./assignment4.txt";
    Solution sol;
    sol.run(path);
}