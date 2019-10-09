class Solution {
public:
    int maxArea(vector<int>& h) {
        int res = 0;
        int left = 0;
        int right = h.size()-1;
        while(left < right){
            res = max(res, min(h[left], h[right]) * (right - left));
            if(h[left] < h[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};