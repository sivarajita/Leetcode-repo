class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int leftsum=0;
        int rightsum=0;
        for(int num:nums){
            rightsum+=num;
        }
        for(int i=0;i<n;i++){
            int val=nums[i];
            rightsum-=val;
            nums[i] = abs(leftsum - rightsum);
            leftsum+=val;

        }
        return nums;
    }
};