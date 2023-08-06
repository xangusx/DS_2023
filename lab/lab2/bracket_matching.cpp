#include <bits/stdc++.h>
using namespace std;

bool check(list<char> *li, list<char>::iterator it, int type){
    it--;
    if(type == 0 && *it == '(')
        return true;
    else if(type == 1 && *it == '[')
        return true;      
    return false;
}

bool bracket_matching(list<char> *li){
    bool ok;
    auto it = li->begin();
    int n;
    n = li->size();
    for(int i=0; i<n; i++){
        // cout<<*it <<endl;
        if(*it == '(' || *it == '['){
            it++;
            continue;
        } 
        else if(*it == ')')
            if(check(li,it,0)){
                it--;
                it = li->erase(it);
                it = li->erase(it);
            }
            else return false;   
        else if(*it == ']')
            if(check(li,it,1)){
                it--;
                it = li->erase(it);
                it = li->erase(it);
            }
            else return false;  
    }
    // cout << "size = " << li->size() <<endl;
    if(li->size() == 0)
        return true;
    else
        return false;
}

int main(){
    int q,n; cin>>q;
    string s;

    while(q--){
        cin>>s;
        if(s == "")
            break;
        list<char> li;
        li.clear();
        for(auto item : s)
            li.push_back(item);

        cout << (bracket_matching(&li) ? "Y" : "N") << endl;
    }
}