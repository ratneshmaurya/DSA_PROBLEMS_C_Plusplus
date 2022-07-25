
//extention of printing LCS Pattern

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();//row
        int m=str2.size();//col
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) dp[i][0]=0; //filling first col
        for(int i=0;i<=m;i++) dp[0][i]=0; //filling first row
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                //if char from back side is same then pass 1 length shorter to recursion function
                //thinking on recursion basis and writing in iterative basis
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        //now traversing backward in dp tabe from bottom right to make printing of LCS and Non-LCS part
        int i=n,j=m;
        string SCS="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1]){
                SCS+=str1[i-1];   //you can also add str2[j-1]
                i--;
                j--;
            }
            //now if left part is greater than upward then first include the upward part and 
            //then move to left
            else
            {
                if(dp[i][j-1]>dp[i-1][j]){
                    SCS+=str2[j-1];
                    j--;
                }
                
                //now if upward part is greater than left then first include the left part and then move to up.
                //remember to use else here, not elseif(dp[i-1][j]>dp[i][j-1]),because equal bhi ho skta, then
                //uske liye kha jaaega,koi toh execute rna pdega, ya upr wala if kro execute yaa ye else part
                
                else{
                    SCS+=str1[i-1];
                    i--;
                }
            } 
        }
        
        //now it might possible that we haven't covered all remaining str1 elements,i.e 
        //j becomes zero earlier than i
        while(i>0){
            SCS+=str1[i-1];
            i--;
        }
        
        //or it might possible that we haven't covered all remaining str2 elements,i.e
        //i becomes zero earlier than j
        while(j>0){
            SCS+=str2[j-1];
            j--;
        }
        
        reverse(SCS.begin(),SCS.end());
        return SCS;
    }
};