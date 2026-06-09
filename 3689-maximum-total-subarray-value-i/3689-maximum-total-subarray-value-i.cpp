class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min_val = nums[0];
        int max_val = nums[0];
        
        // Find the global min and max in a single pass
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        // Calculate the maximum single subarray value
        long long max_single_value = max_val - min_val;
        
        // Return the total value for k identical choices
        return max_single_value * k;
    }
};