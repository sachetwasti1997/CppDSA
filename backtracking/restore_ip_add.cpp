#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void con_list(vector<string> &res, int dots, string tmp, string &s, int indx) {
		if (dots == 4 && indx >= s.size()) {
			res.push_back(tmp.substr(0, tmp.size() - 1));
			return;
		}
		if (dots > 4) return;
		for (int i=indx; i<min(indx+3, (int)s.size()); i++) {
      int tm = stoi(s.substr(indx, i+1 -indx));
			if (tm <= 255 && (i == indx or s[indx] != '0')) {
        con_list(res, dots+1, tmp+to_string(tm)+".", s, i+1);
      }else break;
		}
	}
  vector<string> restoreIpAddresses(string s) {
  	vector<string> res;
		con_list(res, 0, "", s, 0);
		return res;
  }
};