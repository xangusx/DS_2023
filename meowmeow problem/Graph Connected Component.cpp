#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> dsu, sz;
    DSU(int n) {
        dsu.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) dsu[i] = i;
    }
    int get(int x) {
        return (dsu[x] == x ? x : dsu[x] = get(dsu[x]));
    }
    int get_size(int x) {
        return sz[get(x)];
    }
    void oni(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return; 
        if (sz[a] > sz[b]) swap(a, b);
        dsu[a] = b;
        sz[b] += sz[a];
    }
};

int main() {
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        DSU dsu(n);
        int num_components = n;
        int u,v;
        int parent_u, parent_v;
        while(m--){
            cin>>u>>v;
            parent_u = dsu.get(u);
            parent_v = dsu.get(v);

            if (parent_u != parent_v) {
                num_components--;
                dsu.oni(u, v);
            }
        }
        cout << num_components << endl;
    }
    

    
   
}