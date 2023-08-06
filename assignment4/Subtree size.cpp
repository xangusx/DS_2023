#include <bits/stdc++.h>
#define ll long long
using namespace std;

// struct Node{
//     vector<ll> child;
//     ll rank;
// };

ll dfs(ll u, vector<vector<ll>>& pos, vector<bool> &vis, vector<ll>& rank){
    vis[u] = true;
    if(pos[u].size() == 0)
        return 1;
    for(auto i : pos[u]){
        if(vis[i] == false){
            rank[i] = dfs(i, pos, vis, rank);
            rank[u] += rank[i];
        }
    }
    return rank[u];
}

int main(){
    int n; cin>>n;
    vector<vector<ll>> pos(n+1);
    vector<bool> vis(n+1, false);
    vector<ll> rank(n+1,1);
    ll u;
    for(int i=2; i<=n; i++){
        cin>>u;
        pos[u].push_back(i);
    }
    dfs(1, pos, vis, rank);
    for(int i=1; i<=n; i++)
        cout << rank[i]-1 << " ";

}