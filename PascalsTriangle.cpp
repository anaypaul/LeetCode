class Solution {
public:
    int fun(int i, int j){
        if(i==j || j==1){
            return 1;
        }else{
            return fun(i-1,j-1) + fun(i-1,j);
        }
    }
    vector<vector<int> > generate(int numRows) {
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


//Ierative solution 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0){
            return res;
        }
        vector<int> curr;
        curr.push_back(1);
        res.push_back(curr);
        for(int i = 2;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int i = 0;i<curr.size()-1;i++){
                temp.push_back(curr[i] + curr[i+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
            curr = temp;
            temp.clear();
        }
        return res;
    }
};