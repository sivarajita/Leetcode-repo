class Solution {
    int stMax[16][50005];
    int stMin[16][50005];
    int lg[50005];

    void buildSparseTable(const vector<int>& nums, int n) {
        lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < 16; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(stMax[j - 1][i], stMax[j - 1][i + (1 << (j - 1))]);
                stMin[j][i] = min(stMin[j - 1][i], stMin[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int queryVal(int l, int r) {
        int k = lg[r - l + 1];
        int mx = max(stMax[k][l], stMax[k][r - (1 << k) + 1]);
        int mn = min(stMin[k][l], stMin[k][r - (1 << k) + 1]);
        return mx - mn;
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        buildSparseTable(nums, n);

        // Max-heap stores: {subarray_value, {l, r}}
        priority_queue<pair<int, pair<int, int>>> pq;

        // Push the largest window for each starting point 'l'
        for (int l = 0; l < n; l++) {
            pq.push({queryVal(l, n - 1), {l, n - 1}});
        }

        long long totalValue = 0;

        // Extract exactly k maximum values
        while (k-- > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            totalValue += top.first;
            int l = top.second.first;
            int r = top.second.second;

            // If we can shrink the right boundary, push the next candidate
            if (r > l) {
                pq.push({queryVal(l, r - 1), {l, r - 1}});
            }
        }

        return totalValue;
        
    }
};