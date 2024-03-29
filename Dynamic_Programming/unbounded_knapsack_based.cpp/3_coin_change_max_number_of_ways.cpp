// Given a value N, if we want to make change for N cents, and we have infinite supply of each 
// of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins 
// doesn’t matter.
// For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
// So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five 
// solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.


//similar as subset sum problem, bss vha bounded knapsack tha and yha unbounded hai

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        dp[0][0]=1; //if n=0 ans s=0, then an empty set exist
        for(int i=1;i<=amount;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=1;  //empty set can exist
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                
                //if current element smaller than remaining sum needed then we 
                //have two option whether to take this or not take this element
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                
                //else we only have one option that is , we have to leave this element
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};



//---------------------------------------------------------------------------------------------------------
//below is the gfg's recursive approach for understanding the concept 


// int coinchange(vector<int>& a, int v, int n,
//                vector<vector<int> >& dp)
// {
//     if (v == 0)
//         return dp[n][v] = 1;
//     if (n == 0)
//         return 0;
//     if (dp[n][v] != -1)
//         return dp[n][v];
//     if (a[n - 1] <= v) {
//         // Either Pick this coin or not
//         return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
//                           + coinchange(a, v, n - 1, dp);
//     }
//     else // We have no option but to leave this coin
//         return dp[n][v] = coinchange(a, v, n - 1, dp);
// }
