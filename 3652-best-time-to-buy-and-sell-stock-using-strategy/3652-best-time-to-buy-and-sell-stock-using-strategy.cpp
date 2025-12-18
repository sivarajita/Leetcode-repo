class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
          int n = prices.size();
        vector<long long> s(n + 1), t(n + 1);

        for (int i = 1; i <= n; ++i) {
            int a = prices[i - 1];
            int b = strategy[i - 1];
            s[i] = s[i - 1] + 1LL * a * b; 
            t[i] = t[i - 1] + 1LL * a;     
        }

        long long ans = s[n];  
        for (int i = k; i <= n; ++i) {
            long long delta =
                -(s[i] - s[i - k]) +     
                (t[i] - t[i - k / 2]);  
            ans = max(ans, s[n] + delta);
            }
        return ans;
            }
};