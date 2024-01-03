class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0, i=0, j=1;
        int minPrice=prices[0];
        if(n==1) return 0;
        // for(int i=1; i<n; i++) {
        //     minPrice=min(prices[i], minPrice);
        //     maxProfit = max(maxProfit, prices[i] - minPrice);
        // }
        while(j<n) {
            if(prices[j] > prices[i]) {
                int profit = prices[j] - prices[i];
                maxProfit = maxProfit > profit ? maxProfit : profit;
            } else {
                i=j;
            }
            j++;
        }
        return maxProfit;
    }
};
