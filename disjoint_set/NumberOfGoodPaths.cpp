#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class DisSet {
    unordered_map<int, int> parent;
    int cnt = 0;
    vi vals;
public:
    DisSet (vi &val) {
        vals = val;
        cnt = val.size();
        for (int i = 0; i<vals.size(); i++) parent[i] = i;
    }
    
    int find (int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void doUnion (int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (vals[px] > vals[py]) parent[py] = px;
        else if (vals[py] > vals[px]) parent[px] = py;
        else {
            cnt ++;
            parent[px] = py;
        }
    } 
    
    int createDS (vvi &edges) {
        for (auto &i: edges) {
            doUnion(i[0], i[1]);
        }
        return cnt;
    }
};

class Solution {
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    DisSet ds{vals};
    return ds.createDS(edges);
  }
};

int main() {
  Solution s{};
  vi vals{1,3,2,1,3};
  vvi val2{{0,1},{0,2},{2,3},{2,4}};
  cout<<s.numberOfGoodPaths(vals, val2)<<endl;
}