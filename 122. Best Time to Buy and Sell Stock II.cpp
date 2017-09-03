class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=0; i+1<prices.size(); ++i)
            if(prices[i+1] > prices[i])
                profit += prices[i+1] - prices[i];
        return profit;
    }
};
