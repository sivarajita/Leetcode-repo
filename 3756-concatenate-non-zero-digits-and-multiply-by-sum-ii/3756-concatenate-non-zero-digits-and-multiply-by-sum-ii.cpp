class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        // 1. Filter out non-zero digits and track their prefix values/sums
        vector<int> digits;
        vector<long long> P = {0}; // Prefix value array
        vector<long long> S = {0}; // Prefix sum of digits array

        for (char ch : s) {
            if (ch != '0') {
                int digit = ch - '0';
                digits.push_back(digit);
                P.push_back((P.back() * 10 + digit) % MOD);
                S.push_back(S.back() + digit);
            }
        }

        int num_nonzero = digits.size();

        // Precompute powers of 10 modulo MOD
        vector<long long> pow10(num_nonzero + 1, 1);
        for (int i = 1; i <= num_nonzero; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // 2. Build mapping arrays from original string to non-zero indices
        vector<int> next_nonzero(m, num_nonzero);
        vector<int> prev_nonzero(m, -1);

        int curr_idx = 0;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                curr_idx++;
            }
            prev_nonzero[i] = curr_idx - 1;
        }

        curr_idx = num_nonzero - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') {
                curr_idx--;
            }
            next_nonzero[i] = curr_idx + 1;
        }

        // 3. Process each query in O(1) time
        vector<int> answer;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int sub_l = next_nonzero[l];
            int sub_r = prev_nonzero[r];

            // If no non-zero digits exist in the range
            if (sub_l > sub_r) {
                answer.push_back(0);
                continue;
            }

            // Calculate x using the prefix arrays (1-based indexing for P and S)
            long long x = (P[sub_r + 1] - (P[sub_l] * pow10[sub_r - sub_l + 1]) % MOD + MOD) % MOD;
            long long digit_sum = S[sub_r + 1] - S[sub_l];

            long long query_ans = (x * (digit_sum % MOD)) % MOD;
            answer.push_back(query_ans);
        }

        return answer;
    }
};