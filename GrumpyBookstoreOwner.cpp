class Solution {
public:
    bool check(int i, int start, int end){
        return i>= start && i<=end;
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> arr;
        for(int i= 0; i<customers.size(); i++){
            arr.push_back(customers[i] * grumpy[i]);
        }
        int res = 0;
        int start_idx = -1;
        int end_idx = -1;
        vector<int> partial(arr.size(), 0);
        partial[0] = arr[0];
        for(int i= 1; i<arr.size(); i++){
            partial[i] = partial[i-1] + arr[i];
        }
        int val = INT_MIN;
        for(int i = 0; i+X<=arr.size(); i++){
            int t = arr[i] + partial[i+X-1] - partial[i];
            if(val < t ){
                val = t;
                start_idx = i;
                end_idx = i + X - 1;
            }
        }
        for(int i = 0; i<customers.size(); i++){
            if(check(i, start_idx, end_idx)){
                res += customers[i];
            }
            else if(grumpy[i] == 0){
                res += customers[i];
            }
        }
        return res;
    }
};