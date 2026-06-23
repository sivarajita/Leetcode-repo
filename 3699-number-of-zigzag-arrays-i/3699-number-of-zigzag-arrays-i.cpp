class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1e9 + 7;
        int m=r-l+1;
        vector<vector<long long>> dp(m,vector<long long>(2,1));
         vector<vector<long long>> next_dp(m,vector<long long>(2,0));
            vector<long long> pref0(m,0),pref1(m,0);
        for(int i=2;i<=n;i++){
            pref0[0]=dp[0][0];
            pref1[0]=dp[0][1];
            for(int j=1;j<m;j++){
                pref0[j]=(pref0[j-1]+dp[j][0]) % MOD;
                pref1[j]=(pref1[j-1]+dp[j][1]) % MOD;

            }
            for(int j=0;j<m;j++){
                
                    next_dp[j][0]=(j>0) ? pref1[j-1]:0;
        
                
                    next_dp[j][1]=(j<m-1)?(pref0[m-1]-pref0[j]+MOD)%MOD:0;
                }
            
            dp=next_dp;
        }
        long long total_arrays=0;
        for(int j=0;j<m;j++){
            total_arrays=(total_arrays+dp[j][0]+dp[j][1]) % MOD;
        }
        return total_arrays;
    }
};