class Solution {
public:
    int jump(vector<int>& nums) {
        
        int biggerLadder=nums[0]; //greatest ladder formed 
        int currentLadder=nums[0]; //ladder on which we are moving.
        int jump=1;
        if(nums.size()<=1)return 0;
        if(nums[0]==0)return -1;
        for(int i=1;i<nums.size();i++){
            if(i == nums.size()-1)return jump; //statement 1
            
            biggerLadder=max(biggerLadder,i+nums[i]);
            currentLadder--; //becoz moved ahead one step
            
            if(currentLadder==0) {
                currentLadder=biggerLadder-i;
                if(i>biggerLadder)return -1; //when 0 0 0 prr atka rhe currentLadder.
                jump++;
            }
            
//             statement 1 tabhi execute hoga acche se when biggerLadder aage hi rhe 'i' ke, else -1 return hoga
        }
        return -1;
    }
};