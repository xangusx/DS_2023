#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9+7;

void dfs(ll u, ll target, vector<vector<ll>>& adj,vector<ll>& dp){
    if(u == target)
        return;
  	dp[u] = 0;
    for(auto v : adj[u]){
        if(v == u)
            continue;
        if(dp[v] == -1){
          	dp[v] = 0;
            dfs(v, target, adj, dp);   
        }
      	dp[u] = (dp[u]%mod+dp[v]%mod)%mod;
    }
    return;
}

void solve(ll n, vector<vector<ll>>& adj){
    vector<ll> dp(n+1, -1);
    dp[n] = 1;
    dfs(1, n, adj, dp);
    if(dp[1] != -1) cout << dp[1] << endl;
    else cout << "0" << endl;
}

int main(){
    ll n,m; cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    ll u,v;
    while(m--){
        cin>>u>>v;
        adj[u].emplace_back(v);
    }
    solve(n, adj);
}