class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0) return 0;
        
	    int min = prices[0], profit = 0;

	    for (int i = 1; i < prices.size(); ++i) {
		    if (prices[i] < min) {
			    min = prices[i];
		    } else {
			    profit = max(prices[i] - min, profit);
		    }
	    }
	    return profit;
    }
};