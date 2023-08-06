#include <bits/stdc++.h>
using namespace std;

bool f(long n, vector<long>& arr, long m){
    cout << "---"<<endl;
    int temp = 0;
    for(auto i : arr){
        temp += ceil(i/n);
        cout << temp << endl;
        if(temp>m)
            return false;
    }
    return temp <= m ? true : false; 
}

long binary_search(vector<long>&arr, long m){
    long l = 1, mid;
    long r = *max_element(arr.begin(), arr.end());
    sort(arr.begin(), arr.end(), std::greater<long>());
    while(l < r){
        mid = (l + r) / 2;
        cout << mid << endl;
        if(f(mid,arr,m))
            r = mid;
        else
            l = mid +1;
    }
    return r;
}

int main(){
    long n,m;
    cin >> n >> m;
    vector<long> arr(n);
    for(auto &i : arr)
        cin >> i;
    cout << binary_search(arr, m);
}