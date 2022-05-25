

vector<int> help_classmate(vector<int> arr, int n) 
{ 
    // Your code goes here
    stack<int>s;
    s.push(-1);
    vector<int>ans(n,0);// we will push correct value from back hence initialise krna pdd rha phle hi
    
        // agr chota element hai at top then take it as answer and push arr[i] in stack
        // agr bda element hai at top then pop till we get smaller and when we got take 
        // it as answer and push arr[i] in stack for further process
        for(int i=arr.size()-1;i>=0;i--){
        
        while(arr[i]<=s.top()){
            s.pop();
        }
        //answer will be at top of stack
        ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}

