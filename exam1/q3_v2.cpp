#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Iter = vector<pair<ll,ll>>::iterator;
vector<pair<ll,ll>> arr;
// pair(smaller, bigger)
vector<pair<ll,ll>> cmp;

bool mycomp(ll i, ll j) {
    return (i < j);
}

void merge(Iter left, Iter middle, Iter right){

    ll counti = 0, countj = 0;
    ll leni = distance(left, middle)-1;
    ll lenj = distance(middle, right);
    vector<ll> buffer;
    
    Iter i = left, j = middle;
    while (i != middle && j != right) {
        if ((*i).first < (*j).first) {
            counti++;
            cmp[(*i).second].first += countj;
            cmp[(*i).second].second += (lenj - countj);
            buffer.emplace_back(*i);
            i++;

        } else {
            countj++;
            cmp[(*j).second].first += counti;
            cmp[(*j).second].second += (leni - counti);
            buffer.emplace_back(*j);
            j++;
        }
    }
    for (; i != middle; i++){
        cmp[(*i).second].first = lenj;
        buffer.emplace_back(*i);
    }
    for (; j != right; j++){
        cmp[(*j).second].first = leni;
        buffer.emplace_back(*j);
    }
    copy(buffer.begin(), buffer.end(), left);
    return ;
}

void merge_sort(Iter left, Iter right){

    ll count = 0;
    if (left+1 >= right){
        return ;
    } 
    else{
        Iter middle = left + (right - left)/2;
        merge_sort(left, middle);
        merge_sort(middle, right);
        merge(left, middle, right);
    }
    return ;
}

int main(){
    ll n,num;
    cin >> n;
    arr.resize(n);
    cmp.resize(n,make_pair(0,0));

    for(int i=0; i<n; i++){
        cin>>num;
        arr[i].first = num;
        arr[i].second = i;
    }

    merge_sort(arr.begin(), arr.end());
    
    ll count = 0;
    for(int i=0; i<n; i++){
        count += cmp[i].first*cmp[i].second;
    }
    cout << count << "\n";
    for(auto &x : arr) cout << x.first <<" ";

}
