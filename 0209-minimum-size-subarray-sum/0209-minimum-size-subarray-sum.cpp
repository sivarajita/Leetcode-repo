class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, mini = nums.size() + 1, sum = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum >= target) {
                sum -= nums[l];
                mini = min(mini, (r - l + 1));
                l++;
            }

            r++;
        }

        return mini = (mini == nums.size() + 1)? 0 : mini;
    }
};