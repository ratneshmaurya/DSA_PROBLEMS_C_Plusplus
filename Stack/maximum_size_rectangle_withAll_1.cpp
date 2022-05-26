
// GFG passed solution


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    vector<int> nextSmaller(vector<int>&arr, int n) 
    { 
        // Some questions before doing this----------
        // you have to put indexes in stack, how you will handle for -1 index in stack ?
        
        stack<int>s;
        s.push(-1); //initially -1 daal rkha hai
        vector<int>ans(n,0);// we will push correct value from back hence initialise krna pdd rha phle hi
        
        // agr chota element hai at top then take it as answer and push ith index in stack
        // agr bda element hai at top then pop till we get smaller and when we got take 
        // it as answer and push ith index in stack for further process
        for(int i=n-1;i>=0;i--){
        
        //remember stack ke bottom me -1 hai thus arr[-1] check na ho else give segment error
            while(s.top()!=-1 && arr[i]<=arr[s.top()]){
                s.pop();
            }
            //answer will be at top of stack
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int>&arr, int n) 
    { 
        // Your code goes here
        stack<int>s;
        s.push(-1);
        vector<int>ans;
        
        // agr chota element hai at top then take it as answer and push ith index in stack
        // agr bda element hai at top then pop till we get smaller and when we got take 
        // it as answer and push ith index in stack for further process
        for(int i=0;i<n;i++){
        
        //remember stack ke bottom me -1 hai thus arr[-1] check na ho else give segment error
            while(s.top()!=-1 && arr[i]<=arr[s.top()]){
                s.pop();
            }
            //answer will be at top of stack
            ans.push_back(s.top()); //remember yha .push_back hai not arr[i]=s.top(),agr ye krna toh initialise vector like this -- vector<int>ans(n);
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>&arr,int n) {
        vector<int>nS(n);
        vector<int>pS(n);
        nS=nextSmaller(arr,n); //getting all nextSmaller indexed array
        pS=prevSmaller(arr,n); //getting all prevSmaller indexed array
        
        //now running for each index of histogram bar
        int length,bredth,area,maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            length=arr[i];
            
    //becoz nextSmaller ki value ko last index se bda krna pdega if it is -1, tb jaakr bredth dega
            if(nS[i]==-1) nS[i]=n;
            bredth=nS[i]-pS[i]-1;
            
            area=length*bredth;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>store(m); //to store the heights of each column after each row processing
        int maxArea=INT_MIN,area;
        for(int i=0;i<n;i++){
            
            // updating heights of each column
            for(int j=0;j<m;j++){
                store[j]+=M[i][j];
                // now if M[i][j]=0 then it means we assume height nhi hogi uss column ki uss row se uske upr tk
                if(M[i][j]==0) store[j]=0;
            }
            area=largestRectangleArea(store,m);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends