#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator() (pair<int,int> a, pair<int,int> b){
        if(a.second == b.second) return a.first>b.first;
        return a.second>b.second;
    }
};

void solve(int n, int health, priority_queue<pair<int,int>>& attack, priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>& unattack){
    int count = 0;
    bool attack_status = false;
    bool flag = true;
    while(health > 0){
        if(count == n){
            flag = false;
            break;
        }
        if(attack_status){
            while(!unattack.empty() and unattack.top().second >= health){
                // cout << "take out " << unattack.top().first << " " << unattack.top().second << "\n";
                attack.push(unattack.top());
                unattack.pop();
            }
            attack_status = false;
        }
        if(!attack.empty()){
            // cout << "attack " << attack.top().first << " " << attack.top().second << "\n";
            health -= attack.top().first;
            attack.pop();
            count++;
            attack_status = true;
        }
    }
    if(flag) cout << count << "\n";
    else cout << "-1\n";
}

int main(){
    int n, health; cin>>n>>health;
    priority_queue<pair<int,int>> attack;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> unattack;
    int m,c;
    for(int i=0; i<n; i++){
        cin>>m>>c;
        if(c >= health)
            attack.push(make_pair(m,c));
        else
            unattack.push(make_pair(m,c));
    }

    solve(n, health, attack, unattack);
}