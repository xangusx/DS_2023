#include <bits/stdc++.h>
using namespace std;
using Iter = vector<int>::iterator;

bool mycomp(int i, int j) {
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
    vector<int> arr(n);
    map<int, int> m;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        arr[i] = num;
        m[num] = i;
    }

    merge_sort(arr.begin(), arr.end());
    for(auto &x : arr) cout << x <<" ";
  	cout << endl;

    int count = 0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            if(m[arr[i]] > m[arr[j]]){
              	cout << arr[i] << arr[j] << endl;
              	cout << m[arr[j]] << endl;
				count += (m[arr[j]]);
              	// break;
            }
            
        }
    }
}