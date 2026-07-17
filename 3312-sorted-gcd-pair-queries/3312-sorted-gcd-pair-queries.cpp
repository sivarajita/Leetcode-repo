class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
       int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number in nums
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: For each i, find how many numbers are divisible by i
        vector<long long> div_cnt(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                div_cnt[i] += count[j];
            }
        }
        
        // Step 3: Compute exact count of pairs with gcd equal to i
        vector<long long> exact(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long total_pairs = (div_cnt[i] * (div_cnt[i] - 1)) / 2;
            exact[i] = total_pairs;
            // Subtract multiples to get the exact count
            for (int j = 2 * i; j <= max_val; j += i) {
                exact[i] -= exact[j];
            }
        }
        
        // Step 4: Compute prefix sums of the exact GCD counts
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            pref[i] = pref[i - 1] + exact[i];
        }
        
        // Step 5: Answer each query using binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first index where pref[g] > q
            auto it = upper_bound(pref.begin(), pref.end(), q);
            ans.push_back(distance(pref.begin(), it));
        }
        
        return ans; 
    }
};