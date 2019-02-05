class Solution {
public:
    int fun(int i, int j){
        if(i==j || j==1){
            return 1;
        }else{
            return fun(i-1,j-1) + fun(i-1,j);
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i = 1; i<=numRows; i++){
            vector<int> temp;
            for(int j = 1; j<= i ;j++){
                temp.push_back(fun(i,j));
            }
            answer.push_back(temp);
            temp.clear();
        }
        return answer;
    }
};