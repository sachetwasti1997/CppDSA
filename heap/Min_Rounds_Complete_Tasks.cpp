#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumRounds (vector<int> &tasks) {
		priority_queue <int> pq;
		unordered_set<int> sett;
		sett.insert(2);
		sett.insert(3);
		sett.insert(4);
		sett.insert(5);
		sett.insert(6);
		int cnt = 0, rndCnt = 0;
		for (auto &i: tasks) pq.push(i);
		while (!pq.empty()) {
			int tmp = pq.top();
			while (!pq.empty() && pq.top() == tmp) {
				cnt++;
				pq.pop();			
			}
			if (sett.find(cnt) == sett.end()) return -1;
			rndCnt ++;
		} 
		return rndCnt;
	}
};