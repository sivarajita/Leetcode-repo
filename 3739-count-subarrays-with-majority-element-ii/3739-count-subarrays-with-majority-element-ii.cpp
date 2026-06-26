class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // The prefix sum can range from -n to n.
        // We shift everything by +n to keep indices non-negative (0 to 2*n).
        int offset = n;
        vector<int> bit(2 * n + 2, 0);
        
        // Lambda to update Fenwick Tree
        auto update = [&](int idx, int val) {
            for (; idx < bit.size(); idx += idx & -idx) {
                bit[idx] += val;
            }
        };
        
        // Lambda to query prefix frequency sum
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += bit[idx];
            }
            return sum;
        };
        
        long long totalSubarrays = 0;
        int currentPrefixSum = 0;
        
        // Insert the initial prefix sum P[0] = 0 (shifted by offset + 1 for 1-based indexing in BIT)
        update(0 + offset + 1, 1);
        
        for (int x : nums) {
            // Step 1: Update current running prefix sum
            if (x == target) {
                currentPrefixSum += 1;
            } else {
                currentPrefixSum -= 1;
            }
            
            // Step 2: Query how many previous prefixes are strictly less than currentPrefixSum
            // In BIT, strictly less means querying up to (currentPrefixSum + offset)
            totalSubarrays += query(currentPrefixSum + offset);
            
            // Step 3: Add the current prefix sum to the Fenwick tree
            update(currentPrefixSum + offset + 1, 1);
        }
        
        return totalSubarrays;  
    }
};