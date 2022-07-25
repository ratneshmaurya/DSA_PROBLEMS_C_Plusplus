
// ALGO (algo copied from gfg, code written by itself)
// let "len" be the length of the longest common subsequence of str1 and str2
// minimum number of deletions minDel = m – len 
// reason-- as we only need to delete from str1 because we are reducing it to str2
// minimum number of Insertions minInsert = n – len .. Reason--as we are inserting x in str1 , 
// x is a number of characters in str2 which are not taking part in the string which is longest common subsequence 


int minOperations(string text1, string text2) 
	{ 
	    // Your code goes here
	    int n=text1.size(); //row
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
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (n-dp[n][m])+(m-dp[n][m]);
	    
	} 