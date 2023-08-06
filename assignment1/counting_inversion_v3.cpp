#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Print_arr(vector<ll> &arr, int L, int M, int R){

    cout << "left\n";
    for(int i=L; i<=M; i++)
        cout << arr[i] << " ";
    cout << "\nright\n";
    for(int i=M+1; i<=R; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int merge(vector<ll> &arr, int L, int M, int R){
    
    int i = L, j = M;
    int idx = 0;
    int count = 0;
    vector<ll> tmp(R);
    while(i < M && j <=R){
        if(arr[i] <= arr[j]){
            tmp[idx] = arr[i];
            ++idx;
            ++i;
        }
        else{
            tmp[idx] = arr[j];
            count += (M - i);
        }
    }
    while(i < M){
        tmp[idx] = arr[i];
        ++idx;
        ++i;
    }
    while(i < R){
        tmp[idx] = arr[j];
        ++idx;
        ++j;
    }
    for(i=L, idx=0; i<=R; i++, idx++)
        arr[i] = tmp[idx];
    cout << "count = " << count <<endl;
    return count;
}

int merge_sort(vector<ll> &arr, int L, int R){

    int count = 0;
    if (L < R){
        int M = (L + R)/2;
        Print_arr(arr, L,M,R);
        count = merge_sort(arr, L, M);
        count += merge_sort(arr, M+1, R);
        count += merge(arr, L, M+1, R);
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &i : arr)
        cin>>i;

    cout << merge_sort(arr, 0, n-1);
    for(auto &x : arr) cout << x <<" ";
}
