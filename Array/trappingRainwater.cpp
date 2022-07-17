class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int low=0,high=n-1,sum=0;
        int leftmax=height[0],rightmax=height[n-1];
        while(low<=high){
            
            //choosing the side whether to prefer left or right side
            if(leftmax<rightmax){
                
                //if current element is greater than leftmax then first update it
                //remember this step, initially i have written it after sum line
                leftmax=max(leftmax,height[low]);
                sum+=(leftmax-height[low]);
                low++;
            }
            else{
                rightmax=max(rightmax,height[high]);
                sum+=(rightmax-height[high]);
                high--;
            }
        }
        return sum;
    }
};