class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int maxG = 0, maxnow = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; --i) {
            if(maxnow - prices[i] > maxG)
                maxG = maxnow - prices[i];
            if(prices[i] > maxnow)
                maxnow = prices[i];
        }
        return maxG;
    }
};
