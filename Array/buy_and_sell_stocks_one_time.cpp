class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minE=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){
            minE=min(minE,prices[i]);
            profit=max(profit,prices[i]-minE);
        }
        return profit;
    }
};