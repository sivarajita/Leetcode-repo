class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 0;

        // Handle edge case of 1s
        if (counts.count(1)) {
            int one_count = counts[1];
            // We need an odd number of 1s to form a valid pattern
            if (one_count % 2 == 0) {
                max_len = max(max_len, one_count - 1);
            } else {
                max_len = max(max_len, one_count);
            }
        }

        // Check for every other possible starting base x > 1
        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            long long current = val;
            int current_len = 0;

            // Step up the mountain as long as we have at least 2 copies of the current number
            while (counts.count(current) && counts[current] >= 2) {
                current_len += 2;
                current = current * current; // Square it for the next level
            }

            // Check if the final squared value exists to act as the peak element
            if (counts.count(current) && counts[current] >= 1) {
                current_len += 1;
            } else {
                // If there's no peak element, the last element we counted 2 copies of 
                // must act as the peak instead, turning one of its pairs into a single peak.
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};