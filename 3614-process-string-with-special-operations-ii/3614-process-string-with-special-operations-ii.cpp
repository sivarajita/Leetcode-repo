class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n);
        long long curr_len = 0;
        
        // Step 1: Forward Pass to calculate lengths
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (curr_len > 0) curr_len--;
            } else if (s[i] == '#') {
                curr_len *= 2;
            } else if (s[i] == '%') {
                // Length stays the same
            } else {
                // Lowercase English letter
                curr_len++;
            }
            lengths[i] = curr_len;
        }
        
        // If k is out of the final string's bounds
        if (k < 0 || k >= curr_len) {
            return '.';
        }
        
        // Step 2: Backward Pass to trace index k
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '*') {
                // Restoring a character dynamically does not alter the relative target index k
                continue;
            } 
            else if (s[i] == '#') {
                long long prev_len = lengths[i] / 2;
                if (k >= prev_len) {
                    k %= prev_len;
                }
            } 
            else if (s[i] == '%') {
                long long len = lengths[i];
                k = len - 1 - k;
            } 
            else {
                // It's a literal lowercase letter
                long long string_idx = lengths[i] - 1;
                if (k == string_idx) {
                    return s[i];
                }
            }
        }
        
        return '.';
    }
};