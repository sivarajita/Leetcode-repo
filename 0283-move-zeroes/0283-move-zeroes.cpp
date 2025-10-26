class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int first=0,last=0;
        while(last<n)
        {
            if(nums[last]!=0)
            {
                swap(nums[first],nums[last]);
                first++;
            }
            last++;
        }
    }
};