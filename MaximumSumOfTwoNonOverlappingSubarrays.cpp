class Solution {
public:
    vector<pair<int,int>> process(vector<int>& pre , int len, unordered_map<int, pair<int,int>>& m){
        vector<pair<int,int>> res;
        if(len == 1){
            for(int i = 0; i<pre.size(); i++){
                if(i == 0){
                    res.push_back(make_pair(pre[i],res.size()));
                    m[res.size()-1] = make_pair(i, i);
                }else{
                    res.push_back(make_pair(pre[i] - pre[i-1], res.size()));
                    m[res.size()-1] = make_pair(i,i);
                }
            }
        }else{
            res.push_back(make_pair(pre[len-1], res.size()));
            m[res.size()-1] = make_pair(0, len-1);
            for(int i = len; i<pre.size(); i++){
                res.push_back(make_pair(pre[i] - pre[i - len], res.size()));
                m[res.size()-1] = make_pair(i-len+1, i);
            }
        }
        return res;
    }
    bool overlap(pair<int, int> p1, pair<int, int> p2){
        if((p2.first<=p1.first && p1.first <=p2.second) || (p2.first<=p1.second && p1.second<=p2.second)){
            return true;
        }
        if((p1.first<=p2.first && p2.first<=p1.second) || (p1.first<=p2.second && p2.second<=p1.second)){
            return true;
        }
        return false;
    }
    int getMax(vector<pair<int,int>> arr1){
        int max = arr1[0].first;
        int maxIndex = arr1[0].second;
        for(int i=0;i<arr1.size(); i++){
            if(max > arr1[i].first){
                max = arr1[i].first;
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    int solve(vector<pair<int,int>> arr1, unordered_map<int, pair<int,int>> m1, vector<pair<int,int>> arr2, unordered_map<int, pair<int,int>> m2){
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int rows = arr1.size();
        int cols = arr2.size();
        vector<vector<bool>> check(rows, vector<bool>(cols, false));
        for(int i = 0; i<rows;i++){
            for(int j = 0; j<cols; j++){
                if(overlap(m1[arr1[i].second] , m2[arr2[j].second]) == false){
                    check[i][j] = true;
                }
            }
        }
        int res = INT_MIN;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(check[i][j]){
                    res = max(res, arr1[i].first + arr2[j].first);
                }
            }
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = A.size();
        vector<int> pre(n , 0);
        pre[0]= A[0];
        for(int i = 1; i<n; i++){
            pre[i] = A[i] + pre[i-1];
        }
        unordered_map<int, pair<int, int>> m1;
        vector<pair<int, int>> arr1 = process(pre, L, m1);
        unordered_map<int, pair<int, int>> m2;
        vector<pair<int,int>> arr2 = process(pre, M, m2);
        int res = solve(arr1, m1, arr2, m2);
        return res;
    }
};