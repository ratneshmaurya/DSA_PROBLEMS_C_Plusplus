class Solution {
    
  private:
   int helper(int i, int j,string &s, string &t,vector<vector<int>>&dp){
        if(i<0)return j+1; //if string s exhausted then insertion of j+1 characters of string t.
        if(j<0)return i+1; //if strung t exhausted then deletion of i+1 characters of string s.
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]) return (0+helper(i-1,j-1,s,t,dp)); //decrease in both pointers.
        else{
            
            // insert ,,,  delete ,,,  replace ka minimum.
            return dp[i][j]= 1+ min(helper(i,j-1,s,t,dp),min(helper(i-1,j,s,t,dp), helper(i-1,j-1,s,t,dp)));
        }
    }  
  public:
   
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s,t,dp);
    }
};




// iterative dp solution ----- from striver video

public:
   
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]= 1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }