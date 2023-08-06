#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll q; cin>>q;
    ll ans = 0;
    stack<ll> sequence;
    string s;
    while(q--){
        cin>>s;
        ll num;
        if(s == "+" || s == "-"){
            cin>>num;
            bool flag;
            if(s == "+") flag = true;
            else flag = false;
            num = (flag ? num : -num);
            sequence.push(num);
            ans += num;
        }else{
            // cout << "Undo" << endl;
            if(!sequence.empty()){
               num = sequence.top();
               ans -= num;
               sequence.pop();
            }
            // else
            //     cout << "stack is empty\n";
   
        }
    }
    cout << ans << endl;
}