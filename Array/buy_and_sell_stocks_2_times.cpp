
//using gfg concept

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit1=0,profit2=0;
        int buy1=INT_MAX,buy2=INT_MAX;
        for(int i=0;i<n;i++){
            
            buy1=min(prices[i],buy1);
            profit1=max(profit1,prices[i]-buy1);
            
            //buy2 will take that prices[i] that will be smallest becoz the smalles one will give the 
            //minimum after doing prices[i]-profit1
            buy2=min(buy2,prices[i]-profit1);
            profit2=max(profit2,prices[i]-buy2);
        }
        return profit2;
    }
};