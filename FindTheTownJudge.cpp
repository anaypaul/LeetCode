class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> arr(N+1, -1) ;
        for(int i = 0; i<trust.size();i++){
            arr[trust[i][0]] = trust[i][1];
        }
        int count = 0;
        int candidate = -1;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == -1){
                candidate = i;
                count++;
            }
            if(count > 1){
                return -1;
            }
        }
        int c = 0;
        for(int i = 0;i<trust.size();i++){
            if(trust[i][1] == candidate){
                c++;
            }
        }
        if(c== N-1){
            return candidate;
        }else{
            return -1;
        }
    }
};

//Approach 2
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N+1, 0);
        vector<int> out(N+1, 0);
        for(auto x : trust){
            in[x[1]]++;
            out[x[0]]++;
        }
        int judge = -1;
        for(int i = 1; i<in.size(); i++){
            if(in[i] == N-1 && out[i] == 0){
                return i;
            }
        }
        return judge;
    }
};