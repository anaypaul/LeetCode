/*
Pascal's Triangle 2
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back(1);
        vector<int> next(2,1);
        if(rowIndex == 0){
            return prev;
        }else if(rowIndex == 1){
            return next;
        }else{
            for(int i = 2; i<=rowIndex;i++){
                prev.clear();
                prev = next;
                next.clear();
                next.push_back(1);
                for(int i = 0;i<prev.size()-1;i++){
                    next.push_back(prev[i]+prev[i+1]);
                }
                next.push_back(1);
            }
        }
        return next;
        
    }
};

//update
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for(int i = 1; i< rowIndex + 1;i++){
            for(int j = i;j>=1;j--){
                result[j] += result[j-1];
            }
        }
        return result;
    }
};