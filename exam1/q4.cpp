#include <bits/stdc++.h>
using namespace std;
string s;
// pair(value, removal num)
vector<pair<char,int>> removal;


bool check(int p, int n, int m){
    int idx = 0;
    int tmp = 0;
    if(p == m)
        return true;
    else{
        for(int i=0; i<m; i++){
            if(removal[i].second > p){
                tmp++;
                while(s[idx] != removal[i].first){
                    idx++;
                    if(idx > n-1)
                        return false;
                }
                idx++;
            }
        }
        if(idx <= n)
            return true;
        else
            return false;
    }
}

int binary(int n, int m){
    int l, mid, r;
    l = 1;
    r = m;
    while(l < r){
        mid = (l + r) / 2;
        if(check(mid,n,m))
            r = mid;
        else
            l = mid +1;
    }
    return l;
}

int main(){
    cin.tie(NULL),cout.tie(NULL);
    ios::sync_with_stdio(0);
    int n,m; cin>>n>>m;
    removal.clear();
    removal.resize(m);

    cin>>s;
    char ch;
    for(int i=0; i<m; i++){
        cin>>ch;
        removal[i].first = ch;
    }
    int num;
    int serial = 1;
    for(int i=0; i<m; i++){
        cin>>num;
        removal[num-1].second = serial;
        serial++;
    }

    cout << binary(n, m) << "\n";
}