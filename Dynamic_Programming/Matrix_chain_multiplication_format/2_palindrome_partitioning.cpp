
//successfully submitted on leetcode, aditya verma ka exact wala TLE de rha tha

//why we are writing only right recursion code ??
// Here, we need to know minimum no.of cuts, no.of cuts will be minimised when there are palindromic 
// sub-strings in the given original string. if there are no palindromic sub-strings in the given string, 
// then every character will be considered as a palindrome of length of 1, then ans = str_len - 1. In this 
// code first its checking whether left partition is palindrome or not. if its palindrome then only solving 
// right part. Why to do so, if left partition is palindrome obviously no.of cuts will be minimised and our 
// aim is also to know min no.of cuts that's why we are doing like this. Why to waste time on calculating left 
// partition it's not palindrome. Even though we calculate for left partition(which is not palindrome) no.of 
// cuts will be increased but that's not our aim is. So, it's not optimal to calculate for left partition
// (which is not palindrome). You may get doubt that if left partition is not palindrome then this code will 
// not solve for that case. Here, the thing is that case had been already solved in previous recursive calls, 
// when k = 1 -> means during that previous recursion call, every character will be considered as a palindrome 
// of length of 1 and min no.of cuts will be calculated. once try with these examples. S = "bcbade" <- 'bcb' as 
// palindromic sub-string S = "abcde" <- all distinct characters.

class Solution {
    private:
    //for checking palindrome of substrings formed
    bool palindrome(string &s,int start,int end){
        if(start>=end) return true; //becoz if size 0 yaa 1 hui then it is palindrome
        while(start<=end){
            if(s[start]!=s[end]) return false;
            else{
                start++;
                end--;
            }
        }
        return true; //if all gone well
    }
    
    //main helper function
    int helper(string &s,int i,int j)
    {
        if(i>=j)return 0;  //in this case we don't need any partition
        if(dp[i][j]!=-1) return dp[i][j];
        if(palindrome(s,i,j)) return 0;  //if phle se hi ye string palindrome hui, then we don't need any partition
        
        //we are starting from i(i starting from 0, and first ever partition will make 0-0 and 1-n-1),becoz empty string is always in palindrome, so need not to worry, but in case of Matrix chain multiplication question, we have started(or passed value from main function) i from 1, becoz ek matrix exist krni chahiye as uss matrix ki dimension 0th and 1st index dono dekhkrr hi lete the hum (1st matrix start from 0th index to 1st index)
        //basically bss 'i' ki value decide krni pdti, k to 'i' se hi start hota always
        int minAns=2005;
        int left,right;
        for(int k=i;k<=j-1;k++){
             /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(palindrome(s, i, k)){                         
                int temp = helper (s, k+1, j) + 1;
                minAns = min (minAns, temp);
            }
            
//             int temp=helper(s,i,k)+helper(s,k+1,j)+1;  //did +1 for the cost
            
//             if(dp[i][k]!=-1) left=dp[i][k];
//             else{
//                 left=helper(s,i,k);
//             }
            
//             if(dp[k+1][j]!=-1) right=dp[k+1][j];
//             else{
//                 right=helper(s,k+1,j);
//             }
            
//             minAns=min(minAns,left+right+1);
            
           
        }
        dp[i][j]=minAns;
        return dp[i][j];
    }
public:
    int dp[2001][2001];//contraint limit,i.e size of string
    
    //or u can write this in main function and pass dp as reference
    //vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
   
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(s,0,s.size()-1);
    }
};