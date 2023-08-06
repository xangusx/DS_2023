#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool check_permutation(int cnt[]){
    for(int i=0; i<26; i++){
        if(cnt[i] != 0)
            return false;
    }
    return true;
}  

int main(){
    string str1,str2; cin>>str1>>str2;

    int len1 = str1.size(); //substring
    int len2 = str2.size();

    const ll P = 911, M = 1e9+7, N = 1e6;
    vector<ll> p(len2+1);
    vector<ll> myhash(len2+1);
    set<ll> table;
    p[0] = 1;
    int cnt[26] = {0};

    // build hash table
    for(int i=1; i<=len2; i++){
        p[i] = p[i-1] * P % M;
        myhash[i] = (myhash[i-1] + str2[i-1]*p[i-1] % M) % M;
    }
    // build cnt
    for(int i=0; i<len1; i++){
        cnt[int(str1[i])-97]++;
        cnt[int(str2[i])-97]--;
    }
    
    int l = 0, r = len1-1, k = 0;
    ll hashval;
    while(r < len2){
        if(check_permutation(cnt)){
            hashval =  (((myhash[r+1] - myhash[l]) % M * p[len2-l-1]) % M + M) % M;
            table.emplace(hashval);
            cout << r << " " << l << " hashval = " << hashval << "\n";
        }
        cnt[int(str2[l])-97]++;
        l++; r++;
        if(r == len2) break;
        cnt[int(str2[r])-97]--;
    }

    cout << table.size() << "\n";
}