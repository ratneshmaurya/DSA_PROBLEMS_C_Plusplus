
// ALGO---- The idea is to find the LCS(str, str) where str is the input string with the restriction that when 
// both the characters are same, they shouldn’t be on the same index in the two strings.

class Solution {
	public:
		int LongestRepeatingSubsequence(string text1){
		    
    		int n=text1.size(); //row
    		
    		string text2=text1;
            int m=text2.size(); //col
            
            int dp[1001][1001]; // constraint limit
            
            //1st row only
            for(int i=0;i<=m;i++) dp[0][i]=0;  // if string length=0 ,then lcs=0;
            //1st column only
            for(int i=0;i<=n;i++) dp[m][0]=0;  // if string length=0 ,then lcs=0;
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    
                    //if char from back side is same then pass 1 length shorter to recursion function
                    //thinking on recursion basis and writing in iterative basis
                    if(text1[i-1]==text2[j-1] && i!=j){
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