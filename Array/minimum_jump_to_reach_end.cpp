class Solution{
  public:
    int minJumps(int nums[], int n){
        int biggerLadder=nums[0]; //greatest ladder formed 
        int currentLadder=nums[0]; //ladder on which we are moving.
        int jump=1;
        if(n<=1)return 0;
        if(nums[0]==0)return -1;
        for(int i=1;i<n;i++){
            if(i == n-1) return jump;  //statement 1
            
            biggerLadder=max(biggerLadder,i+nums[i]);
            currentLadder--; //becoz moved ahead one step
            
            if(currentLadder==0) {
                currentLadder=biggerLadder-i;
                if(i>=biggerLadder)return -1; //when 0 0 0 prr atka rhe currentLadder.
                // remember to use equal to else the answer will be wrong, becoz biggerLadder bss yhi 
                //tk laa skta it means it is not moving ahead
                jump++;
            }
            
//          statement 1 tabhi execute hoga acche se when biggerLadder aage hi rhe 'i' ke, else -1 return hoga
        }
        return -1;
        
    }
};