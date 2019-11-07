class Solution {
public:
    bool judgeSquareSum(int c) {
        int x = (int)sqrt(c);
        unordered_set<int> s;
        for(int i = 0; i<=x;i++){
            s.insert(i*i);
            if(s.find(c-(i*i)) != s.end()){
                return true;
            }
        }
        return false;
    }
};

//Approach 2
class Solution {
public:
    bool binarySearch(long long int low, long long int high, long long int key){
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(mid * mid == key){
                return true;
            }else if(mid * mid < key){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        int x = (int)sqrt(c);
        for(int i = 0; i<=x;i++){
            int target = c - i*i;
            if(binarySearch(0, target, target)){
                return true;
            }
        }
        return false;
    }
};