#include<bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef long long ll;
class Solution {
public:
    ll comp(ll a, ll b) {
        return a > b ? a : b;
    }
	ll minCost(unordered_map<int, vector<pair<int, int>>> &g, int node, vi &ac, int k, unordered_set<int> &visit, 
										int fwpth, int backpath, ll cost) {
		if (!visit.count(node)) {
			visit.insert(node);
			for (auto &i: g[node]) {
				fwpth += i.second;
				backpath += 2 * i.second;
                cost = comp(fwpth + backpath + ac[i.first-1], cost);
				cost = comp(cost, minCost(g, i.first, ac, k, visit, fwpth, backpath, cost));			
			}
		}
        return cost;
	}
  vll minCost(int n, vvi &roads, vi &appleCost, int k) {
  	unordered_map<int, vector<pair<int, int>>> gr;
	unordered_set<int> visit;
	vll res;
	for (auto &i: roads) {
		gr[i[0]].push_back({i[1], i[2]});
		gr[i[1]].push_back({i[0], i[2]});
	}
	for (auto &i: gr) {
		long long cost = appleCost[i.first - 1];
		minCost(gr, i.first, appleCost, k, visit, 0, 0, cost);
		res[i.first-1] = cost;
	}
    return res;
  }
};

int main() {
    vvi r{{1,2,4},{2,3,2},{2,4,5},{3,4,1},{1,3,4}};
    vi cst{};
}