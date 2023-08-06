#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
using Iter = vector<long long>::iterator;
int merge_sort(Iter left, Iter right);
int merge(Iter left, Iter middle, Iter right);


int merge_sort(Iter left, Iter right){

    static int count = 0;
    if (left+1 >= right){
        return count;
    } 
    else{
        Iter middle = left + (right - left)/2;
        count = merge_sort(left, middle);
        count = merge_sort(middle, right);
        count += merge(left, middle, right);
        cout << "count = " << count << endl;
        return count;
    }
}

int merge(Iter left, Iter middle, Iter right){
    
    printf("merge left\n");
    for(auto i = left;i!=middle;i++) printf("%lld ",*i);
    printf("\n");
    printf("merge right\n");
    for(auto i = middle;i!=right;i++) printf("%lld ",*i);
    printf("\n");

    vector<long long> tmp;
    tmp.clear();
    Iter i = left;
    Iter j = middle;    
    int total = 0, p = 0, q = 0;
    while( i != middle && j != right){
        if( *i < *j){
            i++;
            tmp.emplace_back(*i);
            p++;
            total++;
        }    
        else{
            j++;
            tmp.emplace_back(*j);
            q+=p;
            total++;
        } 
    }
    while(i!=middle){
        tmp.emplace_back(*i);
        i++;
        total++;
    }
    while(j!=right){
        tmp.emplace_back(*j);
        j++;
        total++;
    }

    Iter idx = tmp.begin();
    for(auto i = left; i != right; i++){
        *i = *idx;
        idx++;
    }
    // cout << "total merge = " << total << endl;
    // cout << "q = " << q << endl; 
    // cout << "return = " << ((total/2)*(total/2)-q) << endl;
    return (total/2)*(total/2)-q;

}

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(auto &i : arr) cin >> i;
    cout << merge_sort(arr.begin(), arr.end());
    for(auto &i : arr) cout << i << " ";
}
