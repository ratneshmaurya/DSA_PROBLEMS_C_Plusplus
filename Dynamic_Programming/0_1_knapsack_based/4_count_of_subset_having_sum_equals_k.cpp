
//same as subset sum, but just one difference we have to do addition (becoz we have to 
//return all possible number of subset s that fill the desired sum) instead of OR operation 
//which we do on both the calls during left and right recursion calls.

class Solution{   
public:
    int isSubsetSum(vector<int>arr, int sum){
        
        //think of recursion first
        int n=arr.size();
        int dp[n+1][sum+1];
        dp[0][0]=1; //if n=0 ans s=0, then an empty set exist
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                //if current element smaller than remaining sum needed then we 
                //have two option whether to take this or not take this element
                //and from each answer we have to take addition becoz we are counting the 
                //number of subset that filled desired conditions.
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                
                //else we only have one option that is , we have to leave this element
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};


// below is the copied code of gfg for recursion and memoization for understanding the case of recursion

// int findCnt(int* arr, int i, int required_sum, int n)
// {
//     // Base case
//     if (i == n) {
//         if (required_sum == 0)
//             return 1;
//         else
//             return 0;
//     }
 
//     // If the state has been solved before
//     // return the value of the state
//     if (v[i][required_sum])
//         return dp[i][required_sum];
 
//     // Setting the state as solved
//     v[i][required_sum] = 1;
 
//     // Recurrence relation
//     dp[i][required_sum]
//         = findCnt(arr, i + 1, required_sum, n)
//           + findCnt(arr, i + 1, required_sum - arr[i], n);
//     return dp[i][required_sum];
// }
 