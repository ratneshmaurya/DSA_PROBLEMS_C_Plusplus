class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0,j=0;
        long int sum=0,maxsum=INT_MIN;
        while(j<N){
            
            sum+=Arr[j];  //condition
            
            if(j-i+1 < K) j++;  //making to window size
            
            else{
                maxsum=max(maxsum,sum);  //answer from condition
                sum-=Arr[i];  //adjusting calculation of i before sliding window
                i++;
                j++;
            }
        }
        return maxsum;
    }
};
