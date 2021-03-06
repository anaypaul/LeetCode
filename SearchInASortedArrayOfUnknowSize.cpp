// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = 9999;
        int t = 2147483647;
        while(left<=right){
            int mid =left + (right - left)/2;
            if(reader.get(mid)<t){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        cout<<right;
        left = 0;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(reader.get(mid) == target){
                return mid;
            }else if(target > reader.get(mid)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};


//Approach 2
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0;
        int high = 10000-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int item = reader.get(mid);
            if(item == target){
                return mid;
            }else if(target > item){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};