class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(); 
        int MOD = 1e9 + 7;
        
        board[0][0] = '0';
        board[n-1][n-1] = '0';
        
        // dp[i][j] stores {max_score, path_count}
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};
        
        int dr[] = {1, 0, 1};
        int dc[] = {0, 1, 1};
        
        // FIX: Start i from n - 1 instead of n
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) continue;
                
                int max_s = -1;
                int paths = 0;
                
                for (int d = 0; d < 3; ++d) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    
                    if (ni < n && nj < n && dp[ni][nj].first != -1) {
                        int next_score = dp[ni][nj].first;
                        int next_paths = dp[ni][nj].second;
                        
                        if (next_score > max_s) {
                            max_s = next_score;
                            paths = next_paths;
                        } else if (next_score == max_s) {
                            paths = (paths + next_paths) % MOD;
                        }
                    }
                }
                
                if (max_s != -1) {
                    dp[i][j] = {max_s + (board[i][j] - '0'), paths};
                }
            }
        }
        
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
            
    }
};