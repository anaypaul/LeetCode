#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int binarySearch(vector<int> nums, int low, int high, int target){
    if(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){
            return mid;
        }else if(target > nums[mid]){
            return binarySearch(nums, mid+1, high, target);
        }else{
            return binarySearch(nums, low, mid-1, target);
        }
    }else{
        return -1;
    }
}
vector<vector<int> > find3Sum(vector<int>& nums){
    vector<vector<int> > result;
    set<vector<int> > s;
    sort(nums.begin(), nums.end());
    for(int i =0;i<nums.size();i++){
        for(int j = 0;j<nums.size();j++){}
    }
    return result;
}
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    set<int> s;
    map<int, int> mymap;
    int sum = 0;
    set<vector<int> > result_set;
    for(int i = 0;i<nums.size();i++){
        mymap.insert(make_pair(nums[i],i));
        s.insert(nums[i]);
        sum += nums[i];
    }
    if(s.size()==1 && nums.size()>=3 && sum==0){
        vector<int> t;
        auto it = s.begin();
        t.push_back(*it);
        t.push_back(*it);
        t.push_back(*it);
        result.push_back(t);
        return result;
    }
    for(int i = 0;i<nums.size();i++){
        for(int j = 0;j<nums.size();j++){
            if(i!=j){
                int x = nums[i] + nums[j];
                x = -1*x;
                if(mymap.find(x) != mymap.end()){
                    if(mymap[x] != i && mymap[x]!=j){
                        vector<int> temp;
                        int id = i+j+mymap[x];
                        
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(x);
                        sort(temp.begin(), temp.end());
                        if(result_set.find(temp) == result_set.end()){
                            result_set.insert(temp);
                            result.push_back(temp);
                            temp.clear();
                        }
                        
                    }
                }
            }
        }
    }
    return result;
}
int main(){
    // int arr[] = {-1,0,1,2,-1,-4};
    // int arr[] = {-1,0,1,-1,0,1};
    // int arr[] = {1,2,3};
    int arr[] = {-2,0,1,1,2};
    // int arr[] = {0,0,0,0,0,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> A(arr, arr+n);
    cout<<binarySearch(A, 0, A.size()-1, 2)<<endl;
    // cout<<"Final answer:"<<endl;
    // for(int i = 0; i<ans.size(); i++){
    //     cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    // }

    vector<vector<int> > ans = find3Sum(A);

    cout<<"Final answer:"<<endl;
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }

    
    return 0;
}

//Approach 2:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i =0; i<n;i++){
            if(nums[i] > 0){
                break;
            }
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if( sum < 0){
                    left++;
                }else if(sum > 0){
                    right--;
                }else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    int lastleft = nums[left];
                    int lastright = nums[right];
                    while(left < right && nums[left] == lastleft){
                        left++;
                    }
                    while(left < right && nums[right] == lastright){
                        right--;
                    }
                }
            }
        }
        return res;
    }
};