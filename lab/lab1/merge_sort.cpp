#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
using Iter = vector<long long>::iterator;
void merge_sort(Iter left, Iter right);
void merge(Iter left, Iter middle, Iter right);

void merge_sort(Iter left, Iter right){
    if (left+1 >= right){
        return;
    } 
    else{
        Iter middle = left + (right - left)/2;
        merge_sort(left, middle);
        merge_sort(middle, right);
        merge(left, middle, right);
    }
}

void merge(Iter left, Iter middle, Iter right){

    // printf("merge left\n");
    // for(auto i = left;i!=middle;i++) printf("%lld ",*i);
    // printf("\n");
    // printf("merge right\n");
    // for(auto i = middle;i!=right;i++) printf("%lld ",*i);
    // printf("\n");

    vector<long long> tmp;
    tmp.clear();
    Iter i = left;
    Iter j = middle;
    while( i != middle && j != right){
        if( *i > *j){
            tmp.emplace_back(*i);
            i++;
        }    
        else{
            tmp.emplace_back(*j);
            j++;
        } 
    }
    while(i!=middle){
        tmp.emplace_back(*i);
        i++;
    }
    while(j!=right){
        tmp.emplace_back(*j);
        j++;
    }

    Iter idx = tmp.begin();
    for(auto i = left; i != right; i++){
        *i = *idx;
        idx++;
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
