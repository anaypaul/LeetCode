/*
Pascal's Triangle 2
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev ;
        
        if(rowIndex==0){
            prev.push_back(1);
            return prev;
        }
        if(rowIndex==1){
            prev.push_back(1);
            prev.push_back(1);
            return prev;
        }
        prev.push_back(1);
        prev.push_back(1);
        for(int i = 2;i<=rowIndex; i++){
            int x = prev.size();
            vector<int> curr;
            curr.push_back(1);
            for(int j = 0;j<x-1;j++){
                curr.push_back(prev[j]+prev[j+1]);
            }
            curr.push_back(1);
            prev = curr;
            curr.clear();
        }
        return prev;
    }
};
