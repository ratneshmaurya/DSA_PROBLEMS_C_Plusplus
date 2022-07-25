
//remember, you can do also by two pointer but still complexity will be O(N*M)
//becoz the required largest substring may also exist in ater part of given string
//eg->  s1 = jkjRATjklRATANpw;    s2 = RATAN;
//thus we are doing,better written code atlest

int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[1001][1001]; // constraint limit
        
        //1st row only
        for(int i=0;i<=m;i++) dp[0][i]=0;  // if string length=0 ,then lcs=0;
        //1st column only
        for(int i=0;i<=n;i++) dp[i][0]=0;  // if string length=0 ,then lcs=0;
        
        int maxLength=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                //if char from back side is same then pass 1 length shorter to recursion function
                //thinking on recursion basis and writing in iterative basis
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxLength=max(maxLength,dp[i][j]);
                }
                else{
                    dp[i][j]=0; //becoz discontinuity aa gyi. hence again reset kro
                }
            }
        }
        return maxLength==INT_MIN?0:maxLength;
        
    }