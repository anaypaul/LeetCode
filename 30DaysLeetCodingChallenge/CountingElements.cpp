class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> s;
        for(auto x : arr){
            s.insert(x);
        }
        int res = 0;
        for(int i = 0; i<arr.size(); i++){
            if(s.find(arr[i] + 1) != s.end()){
                res++;
            }
        }
        return res;
    }
};