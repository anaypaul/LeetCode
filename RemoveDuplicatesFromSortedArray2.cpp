#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size()<=2){
        return nums.size();
    }
    int prev = 0;
    int flag = 0;
    for(int i = 1;i<nums.size();){
        if(nums[i] == nums[prev] && flag==0){
            flag = 1;
            nums[prev +1 ] = nums[i];
            i++;
        }else if(nums[i] ==nums[prev] && flag ==1){
            i++;
        }
        
        else if( nums[i] != nums[prev] ){
            if(flag==1){
                prev = prev + 1;
            }
            nums[prev + 1] = nums[i];
            flag = 0;
            prev = prev + 1;
            i++;
        }
    }
    if(flag == 1){
        prev++;
    }
    return prev+1;
}
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int x = removeDuplicates(arr);
    cout<<"complete array:"<<endl;
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"answer : "<<endl;
    for(int i = 0;i<x;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}