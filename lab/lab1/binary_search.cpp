#include <iostream>
#include <vector>
#define ll long long
using namespace std;
using Iter = vector<ll>::iterator;

bool binary_search(vector<ll> &refer,ll query){
    Iter left, right, middle;
    left = refer.begin();
    right = refer.end()-1;
 
    while(left<=right){
        middle = left + (right - left)/2;
        if(*middle == query) return true;
        else{
            if(query > *middle) 
                right = middle-1;  
            else
                left = middle+1;  
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> refer(n), query(m);
    for(auto &i : refer) cin>>i;
    for(auto &j : query) cin>>j;

    for(auto &i : query){
        binary_search(refer, i) ? cout<<"Y " : cout<<"N ";
    }   
}