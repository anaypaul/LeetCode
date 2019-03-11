class Solution {
public:
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void sortColors(vector<int>& nums) {
        int index0 = 0;
        int index1 = 0;
        int index2 = nums.size() - 1;
        while(index1<=index2){
            if(nums[index1] == 0){
                swap(&nums[index1], &nums[index0]);
                index0++;
                index1++;
            }else if(nums[index1]== 1){
                index1++;
            }else{
                swap(&nums[index2], &nums[index1]);
                index2--;
            }
        }
        for(int x : nums){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};