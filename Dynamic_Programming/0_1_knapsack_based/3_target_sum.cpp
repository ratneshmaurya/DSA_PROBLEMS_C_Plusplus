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