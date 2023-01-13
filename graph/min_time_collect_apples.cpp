#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef unordered_map<int, vi> umvi;
typedef unordered_set<int> usi;

int calculate(umvi &gr, int node, vb &hap, usi & vst) {
		int time = 0;
        vst.insert(node);
		for (auto &i: gr[node]) {
			if (!vst.count(i)){
                vst.insert(i);
                time += calculate(gr, i, hap, vst);
            }
		}
		int curr = (!hap[node] && time == 0) || node == 0? 0 : 2;
		return curr + time;
	}
  int minTime(int n, vvi &ed, vb &hap) {
		umvi gr(n);
		usi visit(n);
		for (auto &i: ed) {
            gr[i[0]].emplace_back(i[1]);
            gr[i[1]].emplace_back(i[0]);
        }
		return calculate(gr, 0, hap, visit);
  }

int main() {
  vvi ed = {{},{},{},{},{},{}};
}