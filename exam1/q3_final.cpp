#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll>> arr;
// pair(smaller, bigger)
vector<pair<ll,ll>> cmp;


void merge(ll left, ll middle, ll right){

    ll counti = 0, countj = 0;
    ll leni = middle-left+1;
    ll lenj = right-middle;
    vector<pair<ll,ll>> buffer;
    
    ll i = left, j = middle+1;
    while (i <= middle && j <= right) {
        if (arr[i].first < arr[j].first) {
            counti++;
            cmp[arr[i].second].second += (lenj - countj);
            buffer.emplace_back(arr[i]);
            i++;

        } else {
            countj++;
            cmp[arr[j].second].first += counti;
            buffer.emplace_back(arr[j]);
            j++;
        }
    }
    for (; i <= middle; i++)
        buffer.emplace_back(arr[i]);
    
    for (; j <= right; j++){
        cmp[arr[j].second].first += leni;
        buffer.emplace_back(arr[j]);
    }
    ll tmp = 0;
    for(int x=left; x<=right; x++)
        arr[x] = buffer[tmp++];
    return ;
}

void merge_sort(ll left, ll right){

    ll count = 0;
    if (left == right){
        return ;
    } 
    else{
        ll middle = left + (right - left)/2;
        merge_sort(left, middle);
        merge_sort(middle+1, right);
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

    merge_sort(0, n-1);
    
    ll count = 0;
    for(int i=0; i<n; i++)
        count += cmp[arr[i].second].first*cmp[arr[i].second].second;
    cout << count << "\n";
    // for(auto &x : arr) cout << x.first <<" ";
}
