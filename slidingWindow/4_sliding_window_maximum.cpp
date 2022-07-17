class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int i=0,j=0;
        while(j<nums.size())
        {
            
            //removing all smaller element than nums[j]
            while(!dq.empty() && nums[j]>dq.back()){
                dq.pop_back();
            }
            //pushing the nums[j] int the end size of queue
            dq.push_back(nums[j]);
            
            if(j-i+1 <k) j++;
            
            else if(j-i+1 == k)
            {
                ans.push_back(dq.front());//this will be our answer for current window
                //removing calculations of 'i' before sliding the window
                if(nums[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans;
        
    }
};