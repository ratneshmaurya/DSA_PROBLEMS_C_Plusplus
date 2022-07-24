
// Given a rod of length N inches and an array of prices, price[] that contains 
// prices of all pieces of size smaller than N. Determine the maximum value obtainable
// by cutting up the rod and selling the pieces.
// Example 1:
// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

class Solution{
  public:
    int cutRod(int price[], int n) {
        //making length array;
       int length[n]; // as length is also of n size
       for(int i=0;i<n;i++)
        length[i]=i+1;
        
        //dp of n elements with n size;
        //if length array will be like ki kisi particular length ka hi use kr skte hum bss
        //eg= length={2,5,3,7} then dp[size of length array(i.e 4) +1][n+1] hota 
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <=n; j++) // till size of length
            {
                //if we take it
                if (length[i - 1] <= j)
                    dp[i][j] = max(price[i - 1] + dp[i][j - length[i-1]], dp[i - 1][j]);
    
                //if we don't take it
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][n];
    }
};