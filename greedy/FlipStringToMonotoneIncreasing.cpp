#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minFlipsMonoIncr1(string s) {
		int zero = 0, one = 0;
		for (char &i: s) {
			if (i == '0') zero++;
		}		 	
		int ans = zero;        
		for (char &i: s) {
			if (i == '0') zero --;
			if (i == '1') one ++;
			ans = min(ans, zero + one);			
		}
		return ans;
  }

	int minFlipsMonoIncr(string s) {
		int flips = 0, one = 0;
		for (char &c: s) {
      if (c == '1') one++;
      else if (one > 0) {
        flips++;
        one--;
      }
    }
		return flips;
  }
};