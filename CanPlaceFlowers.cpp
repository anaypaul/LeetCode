class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool ans = false;
        if(flowerbed.size()==0){    return n ==0; }
        if(flowerbed.size()==1){ return (n<=1 && flowerbed[0] == 0)||(n==0);}
        if(flowerbed.size()==2){
            if(n>=2){
                return false;
            }else if(n==1){
                if(flowerbed[0] == 1 || flowerbed[1] == 1){
                    return false;
                }else{
                    return true;
                }
            }
        }
        int x = 0;
        for(int i = 0;i<flowerbed.size();i++){
            if(i==0){
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    x++;
                }
            }else if(i == flowerbed.size()-1){
                if(flowerbed[i]==0 && flowerbed[i-1] ==0){
                    flowerbed[i] = 1;
                    x++;
                }
            }else{
                if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                    flowerbed[i] = 1;
                    x++;
                }
            }
        }
        if(x >=n){
            ans = true;
        }
        return ans;
    }
};