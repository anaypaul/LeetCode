class Solution {
public:
    bool isSame(vector<int> v1, vector<int> v2){
        for(int i = 0; i< v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> transformArray(vector<int>& arr) {
        vector<int> nextday(arr.begin(), arr.end());
        for(int i = 1; i<arr.size()-1;i++){
            if(arr[i-1] < arr[i] &&  arr[i]> arr[i+1]){
                nextday[i] -= 1;
            }
            if(arr[i-1] > arr[i] && arr[i] < arr[i+1] ){
                nextday[i] += 1;
            }
        }
        while(isSame(arr, nextday) == false){
            arr = nextday;
            for(int i = 1; i<arr.size()-1;i++){
                if(arr[i-1] < arr[i] &&  arr[i]> arr[i+1]){
                    nextday[i] -= 1;
                }
                if(arr[i-1] > arr[i] && arr[i] < arr[i+1] ){
                    nextday[i] += 1;
                }
            }
        }
        return nextday;
    }
};