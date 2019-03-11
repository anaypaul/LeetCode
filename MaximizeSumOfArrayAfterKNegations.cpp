class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int sum = 0 ;
        int neg = 0;
        for(int i = 0;i<A.size();i++){
            if(A[i]<0){
                neg++;
            }
        }
        int i = 0;
        while(k>0 && neg>0){
            A[i] = -1 * A[i];
            i++;
            neg--;
            k--;
        }
        if(neg>0){
            if(k%2==0){
                for(int x: A){
                    sum += x;
                }
            }else{
                sort(A.begin(), A.end());
                A[0] = -1*A[0];
                for(int x : A){
                    sum+= x;
                }
            }
        }else{
            if(k%2==0){
                for(int x: A){
                    sum += x;
                }
            }else{
                sort(A.begin(), A.end());
                A[0] = -1*A[0];
                for(int x: A){
                    sum+= x;
                }
            }
        }
        return sum;
    }
};