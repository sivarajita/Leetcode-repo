class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count = 0;
        int neg=0;
        for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            count += 1;
        }
        else if(nums[i]<0){
            neg  += 1;
        }
        }
        return max(count,neg);
        
    }
};