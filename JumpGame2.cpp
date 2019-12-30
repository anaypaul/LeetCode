//Approach 1 : Using BFS
class Solution {
public:
    int jump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<bool> vis(n , false);
        int start = 0;
        vis[start] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(start, 0));
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i = 0; i<= nums[curr.first]; i++){
                if(curr.first + i <n && !vis[curr.first + i]){
                    q.push(make_pair(curr.first + i, curr.second + 1));
                    vis[curr.first + i] = true;
                    if(curr.first + i == n-1){
                        return curr.second + 1;
                    } 
                }
            }
        }
        return false;
    }
};

//Approach 2
class Solution {
public:
    int jump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        if(n <= 1){
            return 0;
        }
        int currMin = 0;
        int currMax = 0;
        int time = 0;
        while(true){
            time++;
            int temp_max = currMax;
            for(int i = currMin; i<=currMax; i++){
                temp_max = max(temp_max, i + nums[i]);
            }
            if(temp_max >= n - 1){
                break;
            }
            currMin = currMax + 1;
            currMax = temp_max;
        }
        return time;
    }
};