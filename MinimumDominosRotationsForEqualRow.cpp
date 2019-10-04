class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> candidates;
        unordered_map<int,int> um;
        for(auto x : A){
            um[x]++;
        }
        for(auto y : B){
            um[y]++;
        }
        for(auto x : um){
            if(x.second >= A.size()){
                candidates.push_back(x.first);
            }
        }
        if(candidates.size() == 0){
            return -1;
        }
        int res = INT_MAX;
        for(auto x : candidates){
            //check for making A same as x
            int temp = 0;
            for(int i = 0;i<A.size(); i++){
                if(A[i] == x){
                    continue;
                }else{
                    if(B[i] == x){
                        temp++;
                    }else{
                        temp = -1;
                        break;
                    }
                }
            }
            //check for making B same as x
            int temp1 = 0;
            for(int i = 0;i<A.size(); i++){
                if(B[i]== x){
                    continue;
                }else{
                    if(A[i] == x){
                        temp1++;
                    }else{
                        temp1 = -1;
                        break;
                    }
                }
            }
            if(temp1 == -1 && temp==-1){
                res = -1;
            }else if(temp1 != -1 && temp!=-1){
                res = min(temp1, temp);
            }else{
                res = max(temp, temp1);
            }
        }
        return res;
    }
};