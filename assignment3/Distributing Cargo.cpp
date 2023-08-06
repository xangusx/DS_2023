#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.first < b.first);
}

void dfs(ll u, vector<vector<pair<ll, ll>>>& adj, vector<ll>& brokenness, vector<pair<ll,ll>>& lowdeveloped){
    // cout << brokenness[u] << "\n";
    for(auto i : adj[u]){
        if(brokenness[i.first] == -1){
            brokenness[i.first] = brokenness[u] + i.second;
            // cout << u << " " << i.first << " " << brokenness[i.first] << "\n";
            dfs(i.first, adj, brokenness, lowdeveloped);
        }   
    }
    if(adj[u].size() <= 1)
        lowdeveloped.emplace_back(make_pair(u,brokenness[u]));
}

int main(){
    int n; cin>>n;
    int q = n-1;
    // pair(vertex, brokenness)
    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<ll> brokenness(n+1,-1);
    vector<pair<ll,ll>> lowdeveloped;
    
    int u,v,b;
    while(q--){
        cin>>u>>v>>b;
        adj[u].emplace_back(make_pair(v,b));
        adj[v].emplace_back(make_pair(u,b));
    }

    brokenness[1] = 0;
    dfs(1, adj, brokenness, lowdeveloped);
    sort(lowdeveloped.begin(), lowdeveloped.end(), cmp);
    for(auto i : lowdeveloped)
        cout << "City " << i.first << ": " << i.second << "\n";
}