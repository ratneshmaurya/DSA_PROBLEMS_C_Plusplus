class Solution 
{
    private:
    bool isValid(int A[], int N, int M, int mid){
        int student=1;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum>mid){
                student++;
                sum=A[i];
            }
            //if at any time the number of our calculating student becomes greater than actual then it is false;
            if(student>M) return false;
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int start=INT_MIN,end=0;
        for(int i=0;i<N;i++){
            start=max(start,A[i]);
            end+=A[i];
        }
        int mid,ans=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            
            //now checking whether this mid value is suitable for valid allocation or not.
            if(isValid(A,N,M,mid)==true){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};