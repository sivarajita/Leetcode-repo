class Solution {
public:
    int findGCD(vector<int>& nums) {
    int min_num=nums[0];
    int max_num=nums[0];
    for(int num:nums){
        if(num<min_num)
        min_num=num;
        if(num>max_num)
        max_num=num;

    }    
    return gcd(min_num,max_num);
    }
};