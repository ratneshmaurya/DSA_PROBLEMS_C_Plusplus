class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>>s;
       vector<int>ans;
       s.push({INT_MAX,-1});  //making this so as to compare it as last element of stack
       if(n==0) return ans;  //returning empty vector if size==0
       
       for(int i=0;i<n;i++){
           while(price[i]>=s.top().first) s.pop();
           
           //if saare elements nikl jaae, means all number left of this index are smaller
           if(s.top().first==INT_MAX) {
               ans.push_back(-1);
           }
           //if saare elements na nikle stack se, means there is a number which is greater found
           else{
               ans.push_back(s.top().second);
           }
           
           //at last push this element with index in stack
           s.push({price[i],i});
       }
       for(int i=0;i<n;i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};
