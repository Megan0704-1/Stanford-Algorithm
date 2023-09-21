#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#define cmp_max(a,b) a>b? a : b
#define cmp_min(a,b) a<b? a : b

using namespace std;

auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; };

class Solution {
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap{cmp};
	string path;
	int ans;

	Solution(string _p):path(_p){};

	void read_file();
	void run();
};

void Solution::read_file(){
	ifstream fh(path);
	int num_symbols;
	fh >> num_symbols;
	int weight; int depth=0;
	while(fh>>weight){
		heap.push({weight, depth});
	}
	cout << "size: " << heap.size() << "\n";
	fh.close();
}

void Solution::run(){
	pair<int, int> a; pair<int, int> b;
	while(heap.size()>=2){
		a = heap.top(); heap.pop();
		b = heap.top(); heap.pop();
		pair<int, int> new_node = decltype(a){a.first+b.first, cmp_min(a.second+1, b.second+1)};
		heap.push(new_node);
		int tmp = cmp_min(a.second+1, b.second+1);
		cout << "add: " << tmp << "\n";
	}
	cout << "run end\n";
	ans = heap.top().second;
	return;
}

int main(int argc, char* argv[]){
	Solution sol(argv[1]);
	sol.read_file();
	sol.run();
	cout << sol.ans << "\n";
	return 0;
}
