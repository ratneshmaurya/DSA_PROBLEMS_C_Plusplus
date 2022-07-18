#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        for(int i=0;i<n;i++) s.push(i);
        
        int a,b;
        while(s.size()>1){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            if(M[a][b]==1) s.push(b);
            else s.push(a);
        }
        
        //now the remaining element can be a possible candidate
        a=s.top();
        
        //now checking if any row=a ka koi element is 1 or not
        //also cheking if col=a ka koi element is 0 or not,except 
        //for the diagonal index wala
        //if any of the above condition meet then it meets that 
        //possible candidate is not a celebrity
        for(int i=0;i<n;i++){
            if(M[a][i]==1) return -1;
            if(M[i][a]==0 && i!=a) return -1;
        }
        return a;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends