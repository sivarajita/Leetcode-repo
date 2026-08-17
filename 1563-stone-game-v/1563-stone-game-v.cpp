class Solution {
int memo[501][501];
    int prefix[501];

    int getSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int i, int j, const vector<int>& stoneValue) {
        // Base case: only one stone left, no more score can be obtained
        if (i >= j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        // Try all possible split points k
        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                // Bob throws right; Alice gets leftSum + optimal score from left part
                maxScore = max(maxScore, leftSum + solve(i, k, stoneValue));
            } else if (leftSum > rightSum) {
                // Bob throws left; Alice gets rightSum + optimal score from right part
                maxScore = max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } else {
                // Ties: Alice chooses the row that yields the higher final score
                int takeLeft = leftSum + solve(i, k, stoneValue);
                int takeRight = rightSum + solve(k + 1, j, stoneValue);
                maxScore = max({maxScore, takeLeft, takeRight});
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Build prefix sums for O(1) range sum queries
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // Initialize memoization table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }

        return solve(0, n - 1, stoneValue);
    }
};