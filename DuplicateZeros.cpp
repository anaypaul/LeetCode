class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        int j = arr.size()-1;
        while(i<= j){
            if(arr[i] == 0){
                j--;
            }
            i++;
            if(i==j){
                break;
            }
        }
        i = arr.size()-1;
        for(; i>=0 && j>=0; ){
            if(arr[j] != 0){
                arr[i] = arr[j];
                i--;j--;
            }else{
                if(i== j){
                    for(int k = arr.size()-1; k> (j <1? 1: j) ;k--){
                        arr[k] = arr[k-1];
                    }
                    arr[i+1] = arr[j];
                    j--;i--;
                    continue;
                }
                arr[i] = arr[j];    
                i--;
                arr[i] = arr[j];
                i--;
                j--;
            }
        }
        
    }
};