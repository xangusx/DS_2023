#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9+7;

ll dfs(ll u, ll target, vector<vector<ll>>& adj,vector<ll>& dp){
    ll count = 0;
    ll tmp;
    if(u == target)
        return 1;
    if(dp[u] != -1)
        return dp[u];
    for(auto v : adj[u]){
        tmp = dfs(v, target, adj, dp);
        (tmp != -1) ? (count = (count%mod+tmp%mod)%mod) : count;
    }

    if(count == 0)
        return -1;
    else{
        dp[u] = count;
        return count;
    }
}

void solve(ll n, vector<vector<ll>>& adj){
    vector<ll> dp(n+1, -1);
    ll ans;
    ans = dfs(1, n, adj, dp);
    if(ans != -1) cout << ans << endl;
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