#include <bits/stdc++.h>
using namespace std;

bool topological_sort(int n, vector<vector<int>>& adj, vector<int> indegree){
    queue<int> q;
    int count = 0;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            cout << i << endl;
            q.emplace(i);
            count++;
        }
    }
    if(count > 1)
        return false;
    int u;
    count = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        cout << u << endl;
        count++;
        for(auto v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.emplace(v);
        }
    }
    return (count == n);
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    int u,v;
    while(m--){
        cin>>u>>v;
        adj[u].emplace_back(v);
        indegree[v]++;
    }
    bool flag = topological_sort(n, adj, indegree);
    cout << (flag ? "YES" : "NO") << endl;
}