class Solution{
    
    public:
    vector<int> next_smaller(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,0);// we will push correct value from back hence initialise krna pdd rha phle hi
        for(int i=arr.size()-1;i>=0;i--){
            
            // agr chota element hai at top then take it as answer and push arr[i] in stack
               if(arr[i]>s.top()){
                   ans[i]=s.top(); //pushing in asnwer vector from back
                   s.push(arr[i]);
               }
               
            //   agr bda element hai at top then pop till we get smaller and when we got take 
            // it as answer and push arr[i] in stack for further process

        // remember answer me jis index ka next smaller nhi mil rha vha -1 jaa rha becoz stack ke bottom me -1 hai hi always
               else{
                   while(arr[i]<=s.top()){
                       s.pop();
                   }
                   ans[i]=s.top();
                   s.push(arr[i]);
               }
        }
        return ans;
    } 
    
};
