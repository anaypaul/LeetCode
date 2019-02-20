class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> sum_arr;
        int curr_sum = 0;
        for(int x : A){
            if(x%2==0){
                curr_sum += x;
            }
        }
        for(int i = 0;i<queries.size();i++){
            int val = queries[i][0];
            int index = queries[i][1];
            if(A[index]%2==0){
                curr_sum -= A[index];
                A[index] += val;
                if(A[index]%2==0){
                    curr_sum += A[index];
                }
            }else{
                A[index] += val;
                if(A[index]%2==0){
                    curr_sum += A[index];
                }
            }
            sum_arr.push_back(curr_sum);
        }
        
        return sum_arr;
    }
};