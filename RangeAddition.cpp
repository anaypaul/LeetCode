// naive approach : time : O(n * k) space : O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = length;
        vector<int> arr(n , 0);
        for(auto u : updates){
            for(int i = u[0]; i<=u[1]; i++){
                arr[i] += u[2];
            }
        }
        return arr;
    }
};
//Approach 2 : range caching 
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = length;
        vector<int> res(n, 0);
        for(auto each : updates){
            res[each[0]] += each[2];
            if(each[1]+1 < n){
                res[each[1] + 1] -= each[2];
            }
        }
        for(int i = 1; i<n; i++){
            res[i] = res[i] + res[i-1];
        }
        return res;
    }
};