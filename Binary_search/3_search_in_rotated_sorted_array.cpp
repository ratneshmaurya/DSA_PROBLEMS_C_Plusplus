
//for concept see the anuj bhaiya video..... best 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int mid;
        while(i<=j)
        {
            mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            
            //else check if left part is sorted and check whether target is in that or not, if not then update the i to mid+1;
            else if(nums[i]<=nums[mid]){
                if(target>=nums[i] && target<=nums[mid]) j=mid-1;
                else i=mid+1;
            }
            
            //else check if right part is sorted and check whether target is in that or not, if not then update the j to mid-1;
            else if(nums[mid]<=nums[j]){
                if(target>=nums[mid] && target<=nums[j]) i=mid+1;
                else j=mid-1;
            }
        }
        return -1;
    }
};