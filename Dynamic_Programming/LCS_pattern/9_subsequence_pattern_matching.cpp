

// Given two strings, find if first string is a subsequence of second
//basically we can easily do it without dp, i.e in linear time by using while loop

bool issubsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    /*If i reaches end of s1,that mean we found all
    characters of s1 in s2,
    so s1 is subsequence of s2, else not*/
    return i == n;
}


//but if thinking how to do with DP ?
//then simply find LCS btwm both string, if length of LCS is same as s1, then return true, else return false.
//below is the code O(n*m) time

// int isSubsequence(string text1, string text2) {
//     int n=text1.size(); //row
//     int m=text2.size(); //col
//     int dp[1001][1001]; // constraint limit
    
//     //1st row only
//     for(int i=0;i<=m;i++) dp[0][i]=0;  // if string length=0 ,then lcs=0;
//     //1st column only
//     for(int i=0;i<=n;i++) dp[i][0]=0;  // if string length=0 ,then lcs=0;
    
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
            
//             //if char from back side is same then pass 1 length shorter to recursion function
//             //thinking on recursion basis and writing in iterative basis
//             if(text1[i-1]==text2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     if(dp[n][m]==n) return true;
//     else return false;
    
// }