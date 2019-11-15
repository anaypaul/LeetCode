//Approach 1 : Naive approach : time - O(n^2)
class Solution {
public:
    int check(vector<int> arr, int i){
        int len = 1;
        int left = i-1;
        int right = i+1;
        int index = i;
        bool flag1 = false;
        bool flag2 = false;
        while(left >=0 && arr[left] < arr[index]){
            left--;
            index--;
            len++;
            flag1 = true;
        }
        index = i;
        while(right < arr.size() && arr[index]> arr[right]){
            right++;
            index++;
            len++;
            flag2 = true;
        }
        return len>=3 && flag1 && flag2 ? len : 0;
    }
    int longestMountain(vector<int>& A) {
        if(A.size()== 0){
            return 0;
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = 0;
        for(int i = 1; i<A.size()-1; i++ ){
            res = max(res, check(A, i));
        }
        return res;
    }
};
//Approach 2: time : O(n)