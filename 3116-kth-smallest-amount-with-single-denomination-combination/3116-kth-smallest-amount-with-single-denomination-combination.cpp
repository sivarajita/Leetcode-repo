class Solution {
private:
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Counts how many distinct amounts <= x can be formed
    long long countMultiples(long long x, const std::vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bit_count = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bit_count++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > x) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bit_count % 2 == 1) {
                total += x / current_lcm;
            } else {
                total -= x / current_lcm;
            }
        }

        return total;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int min_coin = *std::min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = (long long)min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
        
    }
};