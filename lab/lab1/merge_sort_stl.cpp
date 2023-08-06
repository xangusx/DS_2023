
#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Iter = vector<ll>::iterator;

bool mycomp(ll i, ll j) {
    return (i > j);
}

void merge_sort(Iter left, Iter right){
    if (left+1 >= right){
        return;
    } 
    else{
        Iter middle = left + (right - left)/2;
        merge_sort(left, middle);
        merge_sort(middle, right);
        inplace_merge(left, middle,right,mycomp);
    }
}


int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(auto &i : arr) cin >> i;
    merge_sort(arr.begin(), arr.end());
    for(auto &x : arr) cout << x <<" ";
}
