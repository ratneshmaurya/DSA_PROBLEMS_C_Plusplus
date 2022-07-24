
//easy hai chill kro.

// Let sum of subset 1 be s1 and subset 2 with s2
//s2 saare negative wale elements honge, then negative common nikal lo sbka bahar
// s1 - s2  = diff (given)
// s1 + s2=sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1= (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum**


//remember of handling zeros, becoz +0 and -0 will effect the same result so i have extracted 
//the number of count of zeros and then we know that zeros ka kuchh subsets hoga khud ka so we 
//have calculated the number of subset for zeros -- pow(2,countZeros) and did multiply with answer

class Solution {
public:
        int subsetSum(vector<int>& a, int n, int sum,int countZero)
        {
            // Initializing the matrix
            int dp[n + 1][sum + 1];
          // Initializing the first value of matrix
            dp[0][0] = 1;
            for (int i = 1; i <= sum; i++)
                dp[0][i] = 0;
            for (int i = 1; i <= n; i++)
                dp[i][0] = 1;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= sum; j++)
                {
                    //if 0 is there then don't take it
                    if(a[i-1]==0) dp[i][j]=dp[i-1][j];
                    
                    // if the value is greater than the sum
                    else if (a[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
                    else
                          dp[i][j] = dp[i - 1][j];
                }
            }

            return pow(2,countZero)*dp[n][sum];
        }


        int findTargetSumWays(vector<int>& nums, int S) 
        {
            int n=nums.size(),sum=0;
            int countZero=0;
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
                if(nums[i]==0) countZero++;
            }
              
            //making S as positive, becoz our code works for the positive sum subset counts
            S=abs(S);
            //below condition is important
            if(S>sum||(S+sum)%2!=0) return 0;
            int reqSum=(S+sum)/2;
            return subsetSum(nums,n,reqSum,countZero);
        }
};


// below is recursive solution

// class Solution {
// public:
//         int n;
//         int target;
//         map<pair<int,int>,int> cache;
//         int help(vector<int>& nums,int currSum, int i)
//         {
//             auto find = cache.find({i,currSum});

//             if (find != cache.end())
//                 return find->second;

//             if (i == n && currSum == target)
//             {
//                 return 1;
//             }
//             if(i >= n)
//                 return 0;

//             return cache[{i,currSum}] = help(nums,currSum + nums[i],i + 1) + help(nums,currSum - nums[i],i + 1);
//         }

//         int findTargetSumWays(vector<int>& nums, int S) 
//         {
//             n = nums.size();
//             target = S;

//             if(n == 0)
//                 return 0;

//             return help(nums,0,0);
//         }
// };