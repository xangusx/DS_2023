#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,q,idx; cin>>n>>q;
    // hashval(val, string len)
    vector<pair<ll,ll>> hashval (n+1, make_pair(0, 0));
    vector<ll> pw (5010, 1);
    const ll P = 911, M = 1e9+7;
    for(int i = 1; i < 5010; i++)
        pw[i] = pw[i - 1] * P % M;

    string s;
    idx = 1;
    while(n--){
        cin>>s;
        int len = s.size();
        for(int i=0; i<len; i++)
            hashval[idx].first = (hashval[idx].first + s[i]*pw[i] % M) % M;
        hashval[idx].second = len;
        idx++;
    }

    int a,b;
    while(q--){
        cin>>s>>a>>b;
        if(s == "E")
            cout << (hashval[a] == hashval[b] ? "Y\n" : "N\n") ;
        else{
            hashval[a].first = (hashval[a].first + hashval[b].first*pw[hashval[a].second]%M ) % M;
            hashval[a].second += hashval[b].second;
        }
    }
}