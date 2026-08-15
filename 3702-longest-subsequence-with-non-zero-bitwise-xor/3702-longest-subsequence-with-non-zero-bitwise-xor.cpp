class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int txor=0;
        bool non_zero=false;
 for(int x:nums){
    txor^=x;

    if(x!=0)
    non_zero=true;
 }
 if(!non_zero)
 return 0;
 if(txor!=0)
 return nums.size();
 return nums.size()-1;
}
};