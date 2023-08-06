#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;

int main(){
    cin>>s;
    if(s.size() == 1)
        return 0;

    ll len = s.size();
    vector<ll> myhash(len+1);
    vector<ll> p(len+1);
    p[0] = 1;
    const ll P = 911, M = 1e9+7;
    for(ll i=1; i<=len; i++){
        p[i] = p[i-1] * P % M;
        myhash[i] = (myhash[i-1] + s[i-1]*p[i-1] % M) % M;
    }
    for(ll i=1; i<len; i++){
        ll prefix,suffix;
        prefix = myhash[i] * p[len-i] % M;
        suffix = ((((myhash[len] - myhash[len-i]) % M) + M) % M);
        if(prefix == suffix)
            cout << i << " ";
    }
 
}