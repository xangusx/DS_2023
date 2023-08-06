#include <bits/stdc++.h>
using namespace std;
int ans;
void dfs(int u, int parent, vector<vector<int>>& adj, vector<bool>& vis, vector<vector<int>>& dp){
    vis[u] = true;
    if(adj[u].size() == 1 && vis[adj[u][0]] == true){
        dp[u][0] = 0;
        dp[u][1] = 1;
        return;
    }

    for(auto nei : adj[u]){
        if(nei == parent)
            continue;
        if(vis[nei] == false){
            dfs(nei, u, adj, vis, dp);
            dp[u][0] += max(dp[nei][0], dp[nei][1]);
            dp[u][1] += dp[nei][0];
        }
    }
    dp[u][1] ++;
    return;
}

void solve(vector<vector<int>>& adj, int n){
    vector<bool> vis(n+1, false);
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dfs(1, -1, adj, vis, dp);
    // cout << dp[1][0] << " " << dp[1][1]<< endl;
    cout << max(dp[1][0], dp[1][1]);
}

int main(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    int u,v;
    for(int i=2; i<=n; i++){
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    solve(adj, n);
}