class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingposition=-1,endingposition=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                startingposition=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                endingposition=i;
                break;
            }
        }
        return {startingposition, endingposition};
    }
};