    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int mid,next,prev;
        while(i<=j){
            
            //imporatant,becoz if we moved to sorted side(as we must be after some time) 
            //then the first element will be our answer.
            if(nums[i]<nums[j])return nums[i]; 
            mid=i+(j-i)/2;
            next=(mid+1)%n;
            prev=(mid-1+n)%n;
            if(nums[mid]<=nums[next]&& nums[mid]<=nums[prev])return nums[mid];
            else if(nums[i]>nums[mid])j=mid-1;
            else if(nums[mid]>nums[j])i=mid+1;
        }
        return -1;
    }