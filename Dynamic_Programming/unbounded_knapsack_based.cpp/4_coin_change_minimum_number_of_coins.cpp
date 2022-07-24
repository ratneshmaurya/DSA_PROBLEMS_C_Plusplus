// You are given an integer array coins representing coins of different denominations and an
// integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.
// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        //initialization part
        for(int i=0;i<=amount;i++) dp[0][i]=INT_MAX-1; //if array is null then we can't fill amount even if we take infinity
        for(int i=0;i<=n;i++) dp[i][0]=0; //i.e if amount=0 needed then we don't need any coins
        
        // //initialising the second row-----
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0) dp[1][i]=i/coins[0];
        //     else dp[1][i]=INT_MAX-1;
        // }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                
                //if current element smaller than remaining sum needed then we 
                //have two option whether to take this or not take this element
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+ dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                
                //else we only have one option that is , we have to leave this element
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        //remember to check the value
        return dp[n][amount]==INT_MAX-1 ? -1:dp[n][amount];
        
    }
};