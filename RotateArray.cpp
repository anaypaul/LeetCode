//Time Complexity : O(n)
//Space Complexity : O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size(),0);
        for(int i = 0;i<nums.size();i++){
            res[(i+k)%nums.size()] = nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            nums[i] = res[i];
        }
    }
};

//Time Complexity : O(n*k)
//Space Complexity : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp, prev;
        for(int i = 0;i<k;i++){
            prev = nums[nums.size()-1];
            for(int j = 0;j<nums.size();j++){
                temp = nums[j];
                nums[j] = prev;
                prev = temp;
            }
        }
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        int start = 0;
        int end = k -1;
        while(start <= end){
            int t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            start++;
            end--;
        }
        start = k;
        end = nums.size()-1;
        while(start<=end){
            int t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            start++;
            end--;
        }
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for(int start = 0;count<nums.size(); start++){
            int current = start;
            int prev = nums[start];
            do{
                int next_index = (current + k)%nums.size();
                int temp = nums[next_index];
                nums[next_index]= prev;
                prev = temp;
                current = next_index;
                count++;
            }while(start != current);
        }
    }
};