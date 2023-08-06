#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q; cin>>n>>m>>q;
    vector<vector<int>> arr(n+1);
    int v,u;
    while(m--){
        cin>>v>>u;
        arr[v].emplace_back(u);
        arr[u].emplace_back(v);
    }
    string s;
    int num1,num2;
    while(q--){
        cin>>s;
        if(s == "D"){
            cin>>num1;
            cout << arr[num1].size() << "\n";
        }
        else{
            cin>>num1>>num2;
            bool flag = false;
            for(int i=0; i<arr[num1].size(); i++){
                if(arr[num1][i] == num2){
                    flag = true;
                    break;
                }
            }
            cout << (flag ? "Y" : "N") << "\n";
        }
    }
}