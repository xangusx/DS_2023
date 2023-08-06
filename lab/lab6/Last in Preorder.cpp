#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

void preorder(int serial,vector<int>& parent, vector<pair<int,int>>& tree){
    if(serial == -1) return;
    ans.emplace_back(serial);
    preorder(tree[serial].first, parent, tree);
    preorder(tree[serial].second, parent, tree);
}

void inorder(int serial,vector<int>& parent, vector<pair<int,int>>& tree){
    if(serial == -1) return;
    inorder(tree[serial].first, parent, tree);
    ans.emplace_back(serial);
    inorder(tree[serial].second ,parent, tree);
}

int main(){
    int n; cin>>n;
    vector<pair<int,int>> tree(n+1);
    vector<int> parent(n+1, -1);

    for(int i=1; i<=n; i++){
        cin>>tree[i].first>>tree[i].second;
        if(tree[i].first != -1)
            parent[tree[i].first] = i;
        if(tree[i].second != -1)
            parent[tree[i].second] = i;
    }

    for(int i=1; i<=n; i++){
        if(parent[i] == -1){
            // inorder(i, parent, tree);
            preorder(i, parent, tree);
        }
            
    }
    for(auto i : ans)
        cout << i << " ";
    // cout << ans.back();
}