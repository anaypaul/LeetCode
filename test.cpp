//making a max heap.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,1,2,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> v(arr, arr + n);
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}