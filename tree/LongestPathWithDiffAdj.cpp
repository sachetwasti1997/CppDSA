#include<bits/stdc++.h>
using namespace std;
typedef unordered_map<int, vector<int>> umvi; 

class Solution {
public:
  void max_path(umvi &gr, int node, string s, int d[], int & ans) {
    d[node] = 1;
    for (int &i: gr[node]) {
      max_path(gr, i, s, d, ans);
      if (s[i] != s[node]) {
        ans = max(ans, d[i]+d[node]);
        d[node] = max(d[node], d[i]+1);
      }
    }
  }

  int longestPath(vector<int>& parent, string s) {
    umvi gr(parent.size());
    int *d{ new int[parent.size()]{}};
    int ans = 1;
    for (int i=0; i<parent.size(); i++) {
      if (parent[i] != -1) {
        gr[parent[i]].emplace_back(i);
      }
    }
    max_path(gr, 0, s, d, ans);
    delete []d;
    return ans;
  }
};