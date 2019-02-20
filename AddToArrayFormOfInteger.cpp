class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        for(int i = 0;i<A.size();i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
        
        vector<int> num2;
        while(K>0){
            num2.push_back(K%10);
            K = K/10;
        }
        for(int i = 0;i<num2.size();i++){
            cout<<num2[i]<<" ";
        }
        cout<<endl;
        
        int i = 0;
        int carry = 0;
        if(A.size() >= num2.size()){
            cout<<"A is longer or equal"<<endl;
            while(i<num2.size()){
                int x = A[i] + num2[i] + carry;
                if(x>9){
                    carry = x/10;
                    x = x%10;
                }else{
                    carry = 0;
                }
                A[i] = x;
                i++;
            }
            while(i<A.size()){
                int x = A[i] + carry;
                if(x>9){
                    carry = x/10;
                    x = x%10;
                }else{
                    carry = 0;
                }
                A[i] = x;
                i++;
            }
            if(carry != 0){
                A.push_back(carry);
            }
            
            cout<<"output"<<endl;
            for(int i =0;i<A.size();i++){
                cout<<A[i]<<" ";
            }
        }
        else{
            cout<<"num2 is longer"<<endl;
            while(i<A.size()){
                int x = A[i] + num2[i] + carry;
                if(x>9){
                    carry = x/10;
                    x = x%10;
                }
                else{
                    carry = 0;
                }
                A[i] = x;
                i++;
            }
            while(i<num2.size()){
                int x = num2[i] + carry;
                if(x>9){
                    carry = x/10;
                    x = x%10;
                }else{
                    carry = 0;
                }
                A.push_back(x);
                i++;
            }
            if(carry != 0){
                A.push_back(carry);
            }
        }
        reverse(A.begin(), A.end());
        
        return A;
    }
};