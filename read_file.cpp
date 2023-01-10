#include<bits/stdc++.h>
using namespace std;

int main() {
    fstream data_file;
    data_file.open("text.txt");
    string data;
    unordered_map<string, int> mp;
    if (data_file.is_open()) {
        while (getline(data_file, data))
        {
            string wrd;
            int cnt, flg = -1;
            for (auto &i: data) {
                if (flg == 0 && i != ' ') cnt = i - '0';
                else if (i == ',') flg = 0;
                else if (i != ' ') wrd += i;
            }
            mp[wrd] = cnt;
        }
        data_file.close();
    }
    int n = mp.size();
    for (auto &i: mp) cout<<i.first<<", "<<i.second<<endl;
    data_file.open("tewxt.txt");
    unordered_map<string, int> mp2;
    if (data_file.is_open()) {
        while (getline(data_file, data))
        {
            string wrd;
            int cnt, flg = -1;
            for (auto &i: data) {
                if (flg == 0 && i != ' ') cnt = i - '0';
                else if (i == ',') flg = 0;
                else if (i != ' ') wrd += i;
            }
            mp2[wrd] = cnt;
        }
        data_file.close();
        cout <<n<<", "<<mp.size();
    }
    for (auto &i: mp) {
        if (!mp2.count(i.first))cout<<i.first<<", "<<i.second<<"---"<<endl;
    }
    for (auto &i: mp2) {
        if (!mp.count(i.first))cout<<i.first<<", "<<i.second<<endl<<"**";
    }
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
}