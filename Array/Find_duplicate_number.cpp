
// this solution changes the original aray , but this helps to find the multiple duplicates also.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i=0;i<nums.size();i++){
            int index=nums[i]%(nums.size());
            nums[index]+=nums.size();
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]/(nums.size())>=2){
                ans=i;
            }
        }
        return ans;
    }
};


// this is based on cycle detection algorithm --- only for one duplicate element and doesn't modify the array
int findDuplicate(vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[0];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = nums[0];
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow; // or fast
	}
	return -1;
}