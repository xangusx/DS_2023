#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *l, *r;
    int val;
    Node(): l(NULL), r(NULL){}
    Node(int x): l(NULL), r(NULL), val(x){} 
};

Node* build(int l, int r, vector<int>& preorder, vector<int>& pos){
    static int i = 1;
    if(l > r)
        return (Node*)(NULL);
    Node *res = new Node(preorder[i++]);
    res->l = build(l, pos[res->val]-1, preorder, pos);
    res->r = build(pos[res->val]+1, r, preorder, pos);
    return res;
}

void postorder(Node* res){
    if(res == NULL)
        return;
    postorder(res->l);
    postorder(res->r);
    cout << res->val << " ";
}

int main(){
    int n; cin>>n;
    vector<int> preorder(n+1);
    vector<int> inorder(n+1);
    vector<int> pos(n+1);

    for(int i=1; i<=n; i++)
        cin>>preorder[i];
    for(int i=1; i<=n; i++){
        cin>>inorder[i];
        pos[inorder[i]] = i;
    }

    Node *tree = build(1, n, preorder, pos);
    postorder(tree);
}