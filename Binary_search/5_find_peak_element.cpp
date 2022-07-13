class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1,m;
        
        if(n==1) return 0; //else give memory leak error
        
        while(i<=j)
        {
            m=i+(j-i)/2;
            
            if(m>0 && m<n-1) //so that mid wdge wala na bne, uske liye we will write condition separately
            {
                if(nums[m]>nums[m-1] && nums[m]>nums[m+1]) return m;
                
                else if (nums[m]>nums[m-1]) i=m+1;  // moving to increasing slope side;
                
                else j=m-1; //moving to increasing slope side;
            }
            
            //now if mid is on 0th position, just check with the next one.
            else if(m==0){
                if(nums[0]>nums[1]) return 0;
                else return 1;
            }
            
            //if mid is on last position, just check with the previous one.
            else if(m==n-1){
                if(nums[n-1]>nums[n-2]) return n-1;
                else return n-2;
            }
        }
        return -1;
    }
};