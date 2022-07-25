// ALGO is 
// Fill dp matrix by concept of largest repetitive subsequence
//then for printing just do exactly same as you have done for printing LCS, 
//i.e Backtrack from bottom right corner (code of this part will be exactly same as printing of LCS)

int printLongestRepeatingSubsequence(string text1){
		    
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


            //now we got our largest repetitive subsequence dp matrix, now just do backtrack
            
            int i = m, j = n;
            while(i > 0 && j > 0)
            {
                // If current character in both the strings are same, then current character is part of LCS
                if(text1[i - 1] == text2[j - 1])
                {
                    ans.push_back(text1[i-1]);
                    i--;
                    j--;
                }
                // If current character in X and Y are different & we are moving upwards
                else if(dp[i - 1][j] > dp[i][j - 1])
                {
                    i--;
                }
                // If current character in X and Y are different & we are moving leftwards
                else
                {
                    j--;
                }
            }
            reverse(ans.begin(), ans.end());
            cout<<ans;
    	}