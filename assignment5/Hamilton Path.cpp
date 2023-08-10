#include <bits/stdc++.h>
using namespace std;
vector<int> topo;

bool topological_sort(int n, vector<vector<int>>& adj, vector<int> indegree){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.emplace(i);
            topo.emplace_back(i);
        }
    }
    if(topo.size() > 1)
        return false;

    topo.clear();
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        topo.emplace_back(u);
        for(auto v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.emplace(v);
        }
    }
    if(topo.size() != n) return false;

    bool flag;
    for(int i=0; i<n-1; i++){
        flag = false;
        for(auto v : adj[topo[i]]){
            if(v == topo[i+1]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            break;
    }
    return flag;
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
    cout << (flag ? "Yes" : "No") << endl;
}