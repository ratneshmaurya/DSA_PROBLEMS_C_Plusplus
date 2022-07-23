
//  IT IS THE QUESTION OF LEETCODE

//  You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before 
//each integer in nums and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them
// to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.
// Example 1:
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

class Solution {
public:
        int n;
        int target;
        map<pair<int,int>,int> cache;
        int help(vector<int>& nums,int currSum, int i)
        {
            auto find = cache.find({i,currSum});

            if (find != cache.end())
                return find->second;

            if (i == n && currSum == target)
            {
                return 1;
            }
            if(i >= n)
                return 0;

            return cache[{i,currSum}] = help(nums,currSum + nums[i],i + 1) + help(nums,currSum - nums[i],i + 1);
        }

        int findTargetSumWays(vector<int>& nums, int S) 
        {
            n = nums.size();
            target = S;

            if(n == 0)
                return 0;

            return help(nums,0,0);
        }
};