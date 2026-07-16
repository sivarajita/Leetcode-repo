class Solution {
public:
    long long gcdSum(vector<int>& nums) {
      int n = nums.size();
        std::vector<int> prefixGcd(n);
        int current_max = 0;
        
        // Step 1: Construct prefixGcd array
        for (int i = 0; i < n; ++i) {
            current_max = std::max(current_max, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], current_max);
        }
        
        // Step 2: Sort prefixGcd in non-decreasing order
        std::sort(prefixGcd.begin(), prefixGcd.end());
        
        // Step 3 & 4: Form pairs (smallest and largest) and compute their GCD sum
        long long total_sum = 0;
        int left = 0;
        int right = n - 1;
        
        // This loop automatically handles the odd `n` condition by terminating 
        // before `left == right`, leaving the middle element unpaired.
        while (left < right) {
            total_sum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return total_sum;  
    }
};