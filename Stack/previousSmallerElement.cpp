class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int>s;
        vector<int>v;
        s.push(-1);
        
        // agr chota element hai at top then take it as answer and push arr[i] in stack
        // agr bda element hai at top then pop till we get smaller and when we got take 
        // it as answer and push arr[i] in stack for further process
        
        for(int i=0;i<n;i++){
            while(s.top()>=a[i]){
                s.pop();
            }
            
            //answer will be at top of stack
            v.push_back(s.top());
            s.push(a[i]);
        }
        return v;
    }
};