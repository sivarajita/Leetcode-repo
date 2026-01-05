class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),maxprofit=0,buyAtPrice = INT_MAX;
        for(int i=0;i<n;i++){
            
                buyAtPrice = min(buyAtPrice, prices[i]);
                maxprofit = max(maxprofit, prices[i] - buyAtPrice);
        }
        return maxprofit;
    }
};