
// Given an array arr[] of size N, check if it can be partitioned into two parts such that 
//the sum of elements in both parts is the same.
// Example 1:
// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation: 
// The two parts are {1, 5, 5} and {11}.


class Solution{
    private:
    int subsetSum(int N,int *arr,int sum){
        int n=N;
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
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                
                //else we only have one option that is , we have to leave this element
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        //first we calculate sum of the array. If sum is odd, there can not be two 
        //subsets with equal sum, so return false. 
        //and if sum of array elements is even, calculate sum/2 and find a subset 
        //of array with sum equal to sum/2. (i.e subset sum problem with sum=sum/2;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        //if the sum is odd then it 
        if(sum&1==1) return 0;
        else return subsetSum(N,arr,sum/2);
    }
};