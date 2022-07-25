class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(); //row
        int m=text2.size(); //col
        int dp[1001][1001]; // constraint limit
        
        //1st row only
        for(int i=0;i<=m;i++) dp[0][i]=0;  // if string length=0 ,then lcs=0;
        //1st column only
        for(int i=0;i<=n;i++) dp[i][0]=0;  // if string length=0 ,then lcs=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                //if char from back side is same then pass 1 length shorter to recursion function
                //thinking on recursion basis and writing in iterative basis
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
};



// below is the gfg's recursive code for above question 

// int lcs(char* X, char* Y, int m, int n,
//         vector<vector<int> >& dp)
// {
//     if (m == 0 || n == 0)
//         return 0;
//     if (X[m - 1] == Y[n - 1])
//         return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
 
//     if (dp[m][n] != -1) {
//         return dp[m][n];
//     }
//     return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
//                           lcs(X, Y, m - 1, n, dp));
// }