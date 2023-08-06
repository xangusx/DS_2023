#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Iter = vector<ll>::iterator;

bool mycomp(ll i, ll j) {
    return (i < j);
}

ll merge(Iter left, Iter middle, Iter right){

    ll count = 0, idx = distance(left,middle);
    ll n = distance(left,right);
    vector<ll> buffer;
    // copy(left,right,buffer.begin()); // copy to buffer
    // inplace_merge(left, middle,right,mycomp);
    
    Iter i = left, j = middle;
    while (i != middle && j != right) {
        if (*i <= *j) {
            buffer.emplace_back(*i);
            i++;
            idx--;
        } else {
            buffer.emplace_back(*j);
            j++;
            count += idx;
        }
    }
    for (; i != middle; i++) buffer.emplace_back(*i);
    for (; j != right; j++) buffer.emplace_back(*j);
    copy(buffer.begin(), buffer.end(), left);
    // cout << "count = " << count << endl;
    return count;
}

ll merge_sort(Iter left, Iter right){

    ll count = 0;
    if (left+1 >= right){
        return count;
    } 
    else{
        Iter middle = left + (right - left)/2;
        count += merge_sort(left, middle);
        count += merge_sort(middle, right);
        count += merge(left, middle, right);
    }
    return count;
}

int main(){
    ll n;
    cin >> n;
    vector<long long> arr(n);
    for(auto &i : arr) cin >> i;
    cout << merge_sort(arr.begin(), arr.end()) << endl;
    for(auto &x : arr) cout << x <<" ";
}
