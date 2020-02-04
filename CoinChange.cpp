//Approach 1 : 
// Dynamic programming bottom up. 
// calculating the min number of coins required to make i coins i = 1 .. amount. 
// moving from 1 to amount and building using previous calculated results. 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            for(int j = 0; j<coins.size(); j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        if(dp[amount] > amount){
            return -1;
        }
        return dp[amount];
    }
};

//Implementation 2
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<long long int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            int j = coins.size()-1 ;
            while(j>=0){
                if(i - coins[j] >=0){
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
                j--;
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};