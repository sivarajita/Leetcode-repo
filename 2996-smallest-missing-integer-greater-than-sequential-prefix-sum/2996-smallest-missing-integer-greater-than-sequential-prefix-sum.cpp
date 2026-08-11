class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        
        // 1. Calculate sequential prefix sum starting from index 0
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // 2. Insert all numbers into a set for fast lookup
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer >= sum
        while (numSet.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};