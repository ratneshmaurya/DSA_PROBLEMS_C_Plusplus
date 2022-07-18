class Solution
{
    private:
    void solve(stack<int>&s,int count,int size){
        
        if(count==size/2){
            s.pop();
            return;
        }
        //remove the top element and call stack for further operation
        int element=s.top();
        s.pop();
        
        solve(s,++count,size);
        
        //after working ,put back the element
        s.push(element);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        if(sizeOfStack!=0)
        solve(s,0,sizeOfStack);
        // code here.. 
    }
};