class Solution {
public:
    bool isSorted(vector<int>& arr){
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i] <= arr[i+1]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    int getMax(vector<int> arr, int low, int high){
        int maxindex = low;
        int maxval = arr[low];
        for(int i = low; i<high; i++){
            if(maxval < arr[i]){
                maxval = arr[i];
                maxindex = i;
            }
        }
        cout<<maxindex<<endl;
        return maxindex;
    }
    void reverse(vector<int>& arr, int low, int high){
        int i = low;
        int j = high;
        while(i<=j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    vector<int> pancakeSort(vector<int>& A) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        if(A.size() == 0 || A.size() == 1){
            return res;
        }
        int n = A.size();
        int maxFlipSize = n;
        while(isSorted(A) == false){
            int idx = getMax(A, 0, maxFlipSize);
            if(idx != 0){
                reverse(A, 0, idx);
                res.push_back(idx + 1);
            }
            if(isSorted(A) == true){
                return res;
            }else{
                reverse(A, 0, maxFlipSize-1);
                res.push_back(maxFlipSize);
                maxFlipSize--;
            }
        }
        return res;
    }
};