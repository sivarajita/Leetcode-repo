class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_nums_set(nums.begin(), nums.end());
        std::vector<int> unique_nums(unique_nums_set.begin(), unique_nums_set.end());

        // Maximum possible value for elements <= 1500 is < 2048
        const int MAX_VAL = 2048;
        std::vector<bool> current_reachable(MAX_VAL, false);
        current_reachable[0] = true;

        // Step 2: Expand reachable XOR values for 3 rounds (3 picks)
        for (int step = 0; step < 3; ++step) {
            std::vector<bool> next_reachable(MAX_VAL, false);
            
            for (int val = 0; val < MAX_VAL; ++val) {
                if (current_reachable[val]) {
                    for (int num : unique_nums) {
                        next_reachable[val ^ num] = true;
                    }
                }
            }
            current_reachable = std::move(next_reachable);
        }

        // Step 3: Count the total unique XOR triplet values
        int count = 0;
        for (int val = 0; val < MAX_VAL; ++val) {
            if (current_reachable[val]) {
                count++;
            }
        }

        return count;
    }
};