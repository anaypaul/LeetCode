class Solution {
public:
    
    static bool mycmp(vector<int>& v1, vector<int>& v2){
        if(v1[0] > v2[0]){
            return true;
        }else if(v1[0] < v2[0]){
            return false;
        }else if(v1[0] == v2[0]){
            if(v1[1] < v2[1]){
                return true;
            }
            return false;
        }
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = people.size();
        vector<vector<int>> res(n, vector<int>(2, -1));
        sort(people.begin(), people.end(), mycmp);
        for(int i = 0; i< people.size(); i++){
            int idx = people[i][1];
            if(res[idx][1] == -1){
                res[idx] = people[i];
            }else{
                for(int j = n-1; j>idx; j--){
                    res[j] = res[j-1];
                }
                res[idx] = people[i];
            }
        }
        return res;
        
    }
};