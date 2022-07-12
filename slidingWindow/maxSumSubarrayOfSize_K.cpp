class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0,j=0;
        long int sum=0,maxsum=INT_MIN;
        while(j<N){
            sum+=Arr[j];
            if(j-i+1 < K) j++;
            else{
                maxsum=max(maxsum,sum);
                sum-=Arr[i];
                i++;
                j++;
            }
        }
        return maxsum;
    }
};