#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string str1 = "havoc";
    string str2 = "bhvct";
    int m = str1.size();  //rows
    int n = str2.size();  //cols
    // fill the dp table
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    int i = m, j = n;
    while(i > 0 && j > 0)
    {
        // If current character in both the strings are same, then current character is part of LCS
        if(str1[i - 1] == str2[j - 1])
        {
            ans.push_back(str1[i-1]);
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