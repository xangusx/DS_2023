#include <bits/stdc++.h>
using namespace std;

bool is_exist_cookie(int u, vector<int>& cookie){
    for(auto v : cookie){
        if(v == u)
            return true;
    }
    return false;
}

int bfs(int start, vector<vector<int>>& adj, vector<int>& rank, vector<int>& cookie){
    queue<int> que;
    rank[start] = 0;
    que.push(start);
    if(is_exist_cookie(start, cookie))
        return rank[start];
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(auto v : adj[u]){
            if(rank[v] == -1){
                que.push(v);
                rank[v] = rank[u] + 1;
                if(is_exist_cookie(v, cookie))
                    return rank[v];
            }
        }
    }
    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,q; cin>>n>>q;
        vector<vector<int>> adj(n+1);
        vector<int> rank(n+1, -1);
        int u,v;
        while(q--){
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        int start, len; cin>>start>>len;
        vector<int> cookie(len);
        for(int i=0; i<len; i++)
            cin>>cookie[i];
        int ans;
        ans = bfs(start, adj, rank, cookie);
        if(ans == -1)
            cout << "SAD\n";
        else
            cout << ans << "\n";

    }
}