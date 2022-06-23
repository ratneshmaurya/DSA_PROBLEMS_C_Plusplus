
class Solution {
    private:
    int helper(int rem,int i,vector<int>&nums,int &k){
        int ans;
        if(i==nums.size()) return 0;
        if(dp[i][rem]!=-1) return dp[i][rem];
        
        // if length of the current number is greter than remaining space then calculate the cost 
        // and call for next recursion in that is current word in next line and pass the remaining 
        // space after this current word takes place i.e k-nums[i]-1
        if(nums[i]>rem){
            ans=((rem+1)*(rem+1))+ helper(k-nums[i]-1,i+1,nums,k);
        }
        
        // else have two choices whether we can put the current string in same line or not,take min of them
        else{
            int choice1=((rem+1)*(rem+1))+ helper(k-nums[i]-1,i+1,nums,k);
            int choice2=helper(rem-nums[i]-1,i+1,nums,k);
            ans=min(choice1,choice2);
        }
        dp[i][rem]=ans;
        return ans;
    }
public:
    int dp[501][2001]; // dp for ith number of array and remaining space in a line 
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp,-1,sizeof(dp));
        return helper(k,0,nums,k);
    } 
};

