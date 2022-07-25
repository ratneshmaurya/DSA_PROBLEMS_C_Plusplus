
// ALGO===   LCS of(a, reverse(a));


int longestPalinSubseq(string A) {
        
        // string B=reverse(A.begin(),A.end());   -----gives error becoz reverse is of void return type
        
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.size();
        int m=n; // as size will be same;
        
        int dp[1001][1001]; //max constraint ka dp
        
        //1st row only
        for(int i=0;i<=m;i++) dp[0][i]=0;  // if string length=0 ,then lcs=0;
        //1st column only
        for(int i=0;i<=n;i++) dp[m][0]=0;  // if string length=0 ,then lcs=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                //if char from back side is same then pass 1 length shorter to recursion function
                //thinking on recursion basis and writing in iterative basis
                if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }