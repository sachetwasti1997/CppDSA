#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  	if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
		int t = 0, res = 0;
		for (int i=0; i<gas.size(); i++) {
			t += (gas[i] - cost[i]);
			if (t < 0) {
				t = 0;
				res = i+1;
			}
		}      
		return res;
  }
};