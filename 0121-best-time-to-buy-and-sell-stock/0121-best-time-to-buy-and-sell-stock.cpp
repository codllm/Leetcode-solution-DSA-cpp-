class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int minpriceseen = INT_MAX;

        for(int i=0;i<prices.size();i++)
        {
            int price = prices[i];
            profit = max(profit,price-minpriceseen);
            minpriceseen = min(minpriceseen,price);
        }
        return profit;
        
    }
};