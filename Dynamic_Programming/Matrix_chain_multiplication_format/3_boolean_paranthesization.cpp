class Solution{
public:
    unordered_map<string, int> dp ;
    int countWays(int N, string S){
      
      return helper(S, 0 , S.size()-1, 'T') ;
      
    }
    
    int n_ways(int rt, int rf,int lt, int lf ,char sign, char reqBool)
    {
        int temp = 0;
        
        if(sign=='|')
        { 
            if(reqBool=='T')
             { temp+= lt*rt + lf*rt + lt*rf ;  }
            else temp+= lf*rf ;  
        }
        else if(sign=='&')
        {
            if(reqBool=='T')
               temp+= rt*lt ;
            else 
                temp+= lt*rf + lf*rt + lf*rf ;
        }
        else if(sign=='^')
        {
            if(reqBool=='T')
               temp+= lf*rt + lt*rf ;
            else temp+= lf*rf + lt*rt ;   
        }
        
        return temp ;
    }
    
    int helper(string s, int i, int j,char reqBool)
    {
        if(i>j) return 0 ;
        else if(i==j) return reqBool==s[i] ; 
        
        string key = to_string(i) + "" + to_string(j) + " " + reqBool ;
        if(dp.find(key)!=dp.end()) return dp[key] ;
        
        int temp= 0 ;
        for( int k=i+1;k<=j-1;k+=2 )
        {
            int rt = helper(s,k+1,j,'T' ) ;
            int rf = helper(s,k+1,j,'F' ) ;
            int lt = helper(s,i,k-1,'T')  ;
            int lf = helper(s,i,k-1,'F')  ;
            
            temp += n_ways(rt,rf,lt,lf, s[k] , reqBool) ;
        }
        
        return dp[key] = temp%1003 ;
    }
};