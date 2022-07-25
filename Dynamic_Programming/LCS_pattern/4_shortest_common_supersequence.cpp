// Given two strings X and Y of lengths m and n respectively, find the length of the smallest 
// string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.
// Example 1
// Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.



//Length of the shortest supersequence=(Sum of lengths of given two strings) - (Length of LCS of two given strings) 

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int dp[101][101]; // constraint limit
        
        //1st row only
        for(int i=0;i<=n;i++) dp[0][i]=0;  // if string length=0 ,then lcs=0;
        //1st column only
        for(int i=0;i<=m;i++) dp[i][0]=0;  // if string length=0 ,then lcs=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                //if char from back side is same then pass 1 length shorter to recursion function
                //thinking on recursion basis and writing in iterative basis
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m+n-dp[m][n];
    }
};