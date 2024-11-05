class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        for (int i = 0, j = 1; j < prices.size(); j++) {
            while (i < j && prices[i] > prices[j])
                i++;
                
            if (prices[j] - prices[i] > profit)
                profit = prices[j] - prices[i];
        }

        return profit;
    }
};
