class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor=0;
        int non_zero=false;
        for(int x:nums){
            total_xor^=x;
            if(x!=0){
                non_zero=true;
            }
        }
        if(!non_zero)
        return 0;
        if(total_xor!=0)
        return nums.size();
        return nums.size()-1;
    }
};