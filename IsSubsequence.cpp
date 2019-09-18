class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool res = false;
        int i = 0;
        int j = 0;
        int n = s.length();
        int m = t.length();
        while(i < n  && j < m){
            if(s[i] == t[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        if(i == n){
            return true;
        }
        return res;
    }
};


//Follow up - using binary search 
class Solution {
public:
    int searchPos(vector<int> arr, int target){
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] < target){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return low;
    }
    int bsearch(vector<int> arr, int target){
        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target){
                return mid;
            }else if( arr[mid] > target){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        //not found so return the insert position.
        int x = searchPos(arr, target);
        
        x = -1*(x) ;
        x = x -1;
        return x;
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> idx(256, vector<int>(0));
        int n = idx.size();
        int m = idx[0].size();
        
        for(int i = 0;i<t.length(); i++){
            idx[t[i]-'a'].push_back(i);
        }
        
        int last_index = 0;
        for(int i = 0;i<s.length();i++){
            
            if(idx[s[i]-'a'].size() == 0){ //when the character is not present at all in the string t
                return false;
            }

            int index = bsearch(idx[s[i]-'a'] , last_index);
            if(index < 0 ){
                index = -1*(index) -1;
            }
            if(index == idx[s[i]-'a'].size()){
                return false;
            }
            last_index = idx[s[i]-'a'][index] + 1;
        }
        return true;
    }
};