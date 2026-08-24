class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        std::vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Base case: if only the last prefix sum remains
        int ans = pref[n - 1];

        // Traverse backwards from n - 2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            ans = std::max(ans, pref[i] - ans);
        }

        return ans;
    }
};