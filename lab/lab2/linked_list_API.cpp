#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    int n,value; cin>>n;
    string s;
    list<int> l;
    for(int i=0; i<n; i++){
        cin>>s;
        // Insert mode
        if(s == "IT"){
            cin>>value;
            l.push_back(value);
        }
        else if(s == "IH"){
            cin>>value;
            l.push_front(value);
        }
        // Remove mode
        if(s[0] == 'R'){
            if(l.empty())
                continue;
            else if(s[1] == 'T')
                l.pop_back();
            else
                l.pop_front();
        }
        // Search
        if(s == "S"){
          cin>>value;
            if(l.empty()){
                cout << "E\n";
                continue;
            }    
            bool check = false;
            for(auto item : l){
                if(item == value)
                    check = true;
            }
            check ? cout<<"Y \n" : cout<<"N \n";
        }
        // print all of list
        if(s == "O"){
            if(l.empty()){
                cout << "E\n";
                continue;
            }  
            for(auto item: l)
                cout << item <<" ";
            cout << "\n";
        }

    }    
}