//Approach 1 : 
// Start from each index and check if able to reach back to start 
// Time : O(n^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = gas.size();
        for(int i = 0; i<n; i++){
            int start = i;
            vector<bool> vis(n, false);
            queue<int> q;
            q.push(start);
            vis[start] = true;
            int cap = gas[start];
            while(!q.empty()){
                int curr = q.front();
                if(cost[(curr)%n] <= cap){
                    cap -= cost[curr];
                    if(!vis[(curr+1)%n]){
                        q.push((curr + 1)%n);
                        vis[(curr +1)%n] = true;
                        cap += gas[(curr+1)%n];
                    }else{
                        return start;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};
