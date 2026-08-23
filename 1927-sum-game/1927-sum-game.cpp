class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        double sum_diff = 0; // left_sum - right_sum
        
        for (int i = 0; i < n; ++i) {
            double val = (num[i] == '?') ? 4.5 : (num[i] - '0');
            if (i < n / 2) {
                sum_diff += val;
            } else {
                sum_diff -= val;
            }
        }
        
        // Bob wins if and only if the balance is exactly 0
        return sum_diff != 0.0;
        
    }
};