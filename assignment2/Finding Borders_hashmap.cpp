#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    unordered_map<string,bool> m;
    string pref, suff;
    vector<int> idx;

    int len = s.size();
    char ch = s[0];
    int j = (len%2 == 0 ? len/2 : len/2+1);
    for(int i=0; i<len/2; i++){
        if(ch == s[j])
            idx.emplace_back(j);
        pref += s[i];
        m[pref] = true;
        j++;
    }

    for(int i=idx.size()-1; i>=0; i--){
        suff = s.substr(idx[i]);
        if(m[suff] == true)
            cout << suff.size() << " ";
    }
}