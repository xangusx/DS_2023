#include <bits/stdc++.h>
using namespace std;
vector<list<int>> arr;
vector<vector<pair<int,list<int>::iterator>>> pos;
vector<bool> flag;

int main(){
    int n,m; cin>>n>>m;
    arr.resize(n+1);
    pos.resize(n+1);
    flag.resize(n+1, true);


    int num1,num2;
    while(m--){
        cin>>num1>>num2;
        arr[num1].emplace_back(num2);
        arr[num2].emplace_back(num1);
        pos[num1].emplace_back(make_pair(num2, --arr[num2].end()));
        pos[num2].emplace_back(make_pair(num1, --arr[num1].end()));
    }

    int max = 0, idx = 0;
    do{
        max = 0;
        idx = 0;
        for(int i=n; i>0; i--){
            if(flag[i] == false)
                continue;
            // cout << "i = " << i << " " << arr[i].size() << "\n";
            if(arr[i].size() > max){
                max = arr[i].size();
                idx = i;
            }   
        }
        if(idx != 0 ){
            flag[idx] = false;
            cout << idx << " ";
            for(auto it : pos[idx]){
                arr[it.first].erase(it.second);
            }
        }
        
    }while(max != 0);
    for(int i=n; i>0; i--){
        if(flag[i] != false)
            cout << i << " ";
    }
    
}