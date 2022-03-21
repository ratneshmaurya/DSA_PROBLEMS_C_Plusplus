class Solution {
    private:
        int findNextGreater(vector<int>& nums,int index,int pivotIndex)
        {
            int justLarge=pivotIndex;
            for(int i=pivotIndex;i<nums.size();i++){
                
//                 <= needed hai
                if(nums[i]>nums[index] && nums[i]<=nums[justLarge]){
                    justLarge=i;
                }
            }
            return justLarge;
        }
    
        void reverse(vector<int>& nums,int index){
            int left=index,right=nums.size()-1;
            while(left<right){
                swap(nums[left++],nums[right--]);
            }
        }
public:
    void nextPermutation(vector<int>& nums) {
        int i,nextIndex=-1;
        for(i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                nextIndex=findNextGreater(nums,i-1,i);
                swap(nums[nextIndex],nums[i-1]);
                break;
            }
        }
        if(nextIndex==-1){
            reverse(nums,0);
        }
        else{
             reverse(nums,i);
        }
    }
};