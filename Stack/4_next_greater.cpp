class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int>s;
       vector<int>ans;
       s.push(INT_MAX);  //making this so as to compare it as last element of stack
       if(n==0) return ans;  //returning empty vector if size==0
       
       for(int i=n-1;i>=0;i--){
           while(price[i]>=s.top()) s.pop();
           
           //if saare elements nikl jaae, means all number left of this index are smaller
           if(s.top()==INT_MAX) {
               ans.push_back(-1);
           }
           //if saare elements na nikle stack se, means there is a number which is greater found
           else{
               ans.push_back(s.top());
           }
           
           //at last push this element with index in stack
           s.push(price[i]);
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
