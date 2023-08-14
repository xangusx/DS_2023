#include <bits/stdc++.h>
using namespace std;

void solve(int n, int health, priority_queue<pair<int,int>>& attack, vector<pair<int,int>>& unattack){
    int count = 0;
    bool attack_status = false;
    bool flag = true;
    sort(unattack.begin(), unattack.end(),greater<pair<int,int>>());
    int index = 0;
    while(health > 0){
        if(count == n){
            flag = false;
            break;
        }
        if(attack_status){
            while(index < unattack.size() and unattack[index].first >= health){
                // cout << "take out " << unattack.top().first << " " << unattack.top().second << "\n";
                attack.emplace(make_pair(unattack[index].second,unattack[index].first));
                index++;
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
        else{
            flag = false;
            break;
        }
    }
    if(flag) cout << count << "\n";
    else cout << "-1\n";
}

int main(){
    int n, health; cin>>n>>health;
    priority_queue<pair<int,int>> attack;
    vector<pair<int,int>> unattack;
    int m,c;
    for(int i=0; i<n; i++){
        cin>>m>>c;
        if(c >= health)
            attack.push(make_pair(m,c));
        else
            unattack.push_back(make_pair(c,m));
    }

    solve(n, health, attack, unattack);
}