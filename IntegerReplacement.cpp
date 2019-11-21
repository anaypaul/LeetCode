class Solution {
public:
    unordered_map<long long int,int> m;
    int helper(long long int n, int step){
        if(n == 1){
            return step;
        }
        if(n%2 == 0){
            if(m.find(n/2) != m.end()){
                return m[n/2];
            }else{
                return helper(n/2, step+1);
            }
        }
        int x, y;
        if(m.find(n+1) != m.end()){
            x = m[n+1];
        }else{
            x = helper(n+1, step + 1);
        }
        if(m.find(n-1) != m.end()){
            y = m[n-1];
        }else{
            y = helper(n-1, step + 1);
        }
        return min(x, y);
    }
    int integerReplacement(int n) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return helper(n, 0);
    }
};