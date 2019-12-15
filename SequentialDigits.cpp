class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        queue<int> q;
        for(int i = 1; i<=9; i++){
            q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(x <= high && x >= low){
                res.push_back(x);
            }
            if(x > high){
                break;
            }
            int num = x % 10;
            if(num < 9){
                q.push(x *10 + (num+1));
            }
        }
        return res;
    }
};