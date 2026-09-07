class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> ends_with(26, 0);
        long long total = 0; // Tracks sum of all distinct subsequences so far

        for (char ch : s) {
            int idx = ch - 'a';
            // 1 accounts for the single-character subsequence "ch"
            long long new_count = (total + 1) % MOD;
            
            // Update total by removing old ends_with[idx] and adding new_count
            total = (total - ends_with[idx] + new_count + MOD) % MOD;
            ends_with[idx] = new_count;
        }

        return total;
    }
};