//Two pointer approach 
//Time complexity : O(n) , Space complexity : O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                left++;
            }else{
                height[right] >=right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
//Dynamic programming approach
//store max from left to right
//store max from right to left 
// add min(max_left, max_right) - height[i] to result

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(n==0){
            return 0;
        }
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        for(int i = 1;i<n;i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }
        for(int j = n-2;j>=0 ;j--){
            right_max[j] = max(height[j], right_max[j+1]);
        }
        for(int i = 0;i<n ; i++){
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};