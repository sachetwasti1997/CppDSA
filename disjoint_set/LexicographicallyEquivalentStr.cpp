#include<bits/stdc++.h>
using namespace std;

class DisSet {
	int n;
	unordered_map<char, char> parent;
	unordered_map<char, int> rank;

public:
	
	char find(char &x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}
	
	void unionse(char &x, char &y) {
		char px = find(x);
		char py = find(y);
		if (px == py) return;
		if (rank[px] < rank[py]) parent[px] = py;
		else if (rank[px] > rank[py]) parent[py] = px;
		else {
			if (px > py) {
				parent[px] = py;
				rank[py]++;
			}else {
				parent[py] = px;
				rank[px]++;
			}
		}
	}
	
	void construct(string &x, string &y) {
		for (int i=0; i<x.size(); i++) {
			unionse(x[i], y[i]);
		}
	}	

	DisSet(string &s1, string &s2) {
		string s = s1 + s2;
		for (char &i: s) {
			parent[i] = i;
			rank[i] = 1;
		}
		construct(s1, s2);
	}

	bool contains(char &x) {
		return parent.count(x);
	}
	
};

class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
		DisSet ds{s1, s2};
		string res;
		for (char &c: baseStr) {
			if (ds.contains(c)) {
				res += ds.find(c);
			}else {
				res += c;
			}
		}
		return res;
  }
};

int main() {
	string s1 = "leetcode", s2 = "programs", b="sourcecode";
  Solution ds{};
	ds.smallestEquivalentString(s1, s2, b);
}

