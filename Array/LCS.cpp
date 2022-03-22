// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int N)
    {
      //Your code here
        unordered_map<int,int>m;
        int i=0;
        while(i<N){
            m[nums[i++]]++;
        }
        
        int element,length,maxlength=0;
        for(int j=0;j<N;j++)
        {
            length=0;
            if(!m[nums[j]-1])
            {                
                element=nums[j];
                while(m[element])
                {
                    length++;
                    element+=1;
                }
            }
            maxlength=max(maxlength,length);
        }
        return maxlength;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends