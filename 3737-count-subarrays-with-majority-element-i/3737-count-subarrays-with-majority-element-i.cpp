class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int targetCount = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    targetCount++;
                }
                int length = j - i + 1;
                if (targetCount * 2 > length) {
                    result++;
                }
            }
        }
        
        return result;
    }
};