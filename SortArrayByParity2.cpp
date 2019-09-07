class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int index = 0;
        for(int i =0;i<A.size();){
            if(i%2==1 && A[i]%2==0){
                swap(A[i], A[index]);
                index += 2;
            }else{
                i++;
            }
        }
        return A;
    }
};