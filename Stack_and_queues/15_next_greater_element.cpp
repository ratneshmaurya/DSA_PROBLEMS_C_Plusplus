class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>s;
        s.push(-1);
        vector<long long>ans(n,0);
        for(int i=n-1;i>=0;i--){
            //till it is greater than s.top() and s.top() not becomes -1(i.e right side kuchh nhi bacha ab array ke liye)
            while(!s.empty() && arr[i]>s.top() && s.top()!=-1) s.pop();

            ans[i]=s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};