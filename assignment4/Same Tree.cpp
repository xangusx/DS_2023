#include <bits/stdc++.h>
using namespace std;
int idx;
struct Node{
    Node *l, *r;
    string val;
    Node(): l(NULL), r(NULL){}
    Node(string x): l(NULL), r(NULL), val(x){} 
};

Node* build(int l, int r, vector<string>& preorder, unordered_map<string, int>& pos, int n){
    if(l > r || idx > n)
        return (Node*)(NULL);
    Node *res = new Node(preorder[idx++]);
    if(pos.find(res->val) != pos.end()){
        res->l = build(l, pos[res->val]-1, preorder, pos, n);
        res->r = build(pos[res->val]+1, r, preorder, pos, n);
        cout << "l:" << l << ",pos[res->value] - 1:" << pos[res->val] - 1 << ",pos[res->value] + 1:" << pos[res->val] + 1 << ",r:" << r << "\n";
    }else
        return (Node*)(NULL);

    return res;
}

bool build_postorder(Node* res, vector<string>& postorder){
    if(res == NULL)
        return true;
    if(!build_postorder(res->l, postorder))
        return false;
    if(!build_postorder(res->r, postorder))
        return false;
    // cout << res->val << " ";
    if(res->val == postorder[idx++])
        return true;
    else
        return false;
}

int main(){
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        vector<string> preorder(n+1);
        vector<string> inorder(n+1);
        vector<string> postorder(n+1);
        unordered_map<string, int> pos;
        for(int i=1; i<=n; i++)
            cin>>preorder[i];
        for(int i=1; i<=n; i++){
            cin>>inorder[i];
            pos[inorder[i]] = i;
        }
        for(int i=1; i<=n; i++)
            cin>>postorder[i];

        idx = 1;
        Node *tree = build(1, n, preorder, pos, n);
        idx = 1;
        cout << (build_postorder(tree, postorder) ? "yes" : "no") << "\n";
    }
}