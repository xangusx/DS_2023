#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll q; cin>>q;
    while(q--){
        ll n,k;
        cin>>n>>k;
        list<ll> li;
        vector<list<ll>::iterator> pos(n);
        
        for(int i=0; i<n; i++){
            li.emplace_back(i+1);
            pos[i] = (--li.end());
        }
        // for(auto i:pos)
        //     cout << *i << " ";
        //     cout << endl;

        ll num = 0;
        while(k--){
            cin>>num;
            if(pos[num-1] != li.end()){
                if(next(pos[num-1]) != li.end()){
                    cout << *(next(pos[num-1])) << "\n";
                    pos[*(next(pos[num-1]))-1] = li.end(); // update the location of the deleted number
                    li.erase(next(pos[num-1]));
                }else{
                    cout << "Penguin07 QQ\n";
                }
            }else{
                cout << "Penguin07 QQ\n";
            }
            
        }
    }
}