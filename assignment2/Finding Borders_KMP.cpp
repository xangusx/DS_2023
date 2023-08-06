#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    string suff;
    int len = s.size();
    int j = (len%2 == 0 ? len/2 : len/2+1);
    suff = s.substr(j);

    int idx = 0,k = 0;
    bool flag;
    while(idx != suff.size()){
        flag = true;
        if(s[idx] != suff[idx+k]){
            flag = false;
            k = idx+1;
            idx = -1;
        }
        idx++;
    }
    if(flag = false)
        cout << len-k-1;
    else
        cout << idx;


}