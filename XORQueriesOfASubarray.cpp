class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto each : queries){
            int x = arr[each[0]];
            for(int i = each[0]+1; i<=each[1]; i++){
                x ^= arr[i];
            }
            res.push_back(x);
        }
        return res;
    }
};

//Approach 2 : Time : O(n)
// Space : O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size()+1);
        for(int i = 0; i<arr.size(); i++){
            pre[i+1] = pre[i] ^ arr[i];
        }
        vector<int> res;
        for(auto q : queries){
            res.push_back(pre[q[0]] ^ pre[q[1]+1]);
        }
        return res;
    }
};