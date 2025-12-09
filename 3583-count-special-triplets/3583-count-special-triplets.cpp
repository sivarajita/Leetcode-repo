class Solution {
public:
    int specialTriplets(vector<int>& nums) {
       const int MOD = 1e9 + 7;
       unordered_map<int,int>left,right;
       long long ans=0;
       for(int x:nums)
       right[x]++;
       for(int x:nums){
        right[x]--;
        int target=2*x;
        ans=(ans+(long long)left[target]*right[target]) % MOD;
        left[x]++;
       }
       return ans;
    }
};