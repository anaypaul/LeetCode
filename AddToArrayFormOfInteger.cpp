class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int carry = 0;
        int x = 0;
        int i;
        for(i = 0;i<A.size() && K>0;i++){
            x = carry + A[i] + K%10;
            K = K/10;
            A[i] = x%10;
            carry = x/10;
        }
        while(i<A.size()){
            x = carry + A[i] ;
            A[i] = x%10;
            carry = x/10;
            i++;
        }
        while(K>0){
            x = carry + K%10;
            K = K/10;
            A.push_back(x%10);
            carry = x/10;
        }
        if(carry){
            A.push_back(carry);
        }
        reverse(A.begin(), A.end());
        return A;
    }
};