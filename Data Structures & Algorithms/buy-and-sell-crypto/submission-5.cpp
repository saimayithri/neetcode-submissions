class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0;
        int maxProfit = 0;

        for(int r = 1; r < prices.size(); r++)
        {
            
            if(prices[r] > prices[l])
            {
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            }
            else
            {
                
                l = r;
            }
        }

        return maxProfit;
    }
};