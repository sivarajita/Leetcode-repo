class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nodes(n);
        vector<int> original_to_sorted(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());
        
        for (int i = 0; i < n; ++i) {
            original_to_sorted[sorted_nodes[i].second] = i;
        }

        // 2. Determine greedy right-parent using sliding window
        int LOG = 18; 
        vector<vector<int>> up(n, vector<int>(LOG));
        
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && sorted_nodes[r].first - sorted_nodes[l].first <= maxDiff) {
                r++;
            }
            // furthest reachable node to the right is r - 1
            up[l][0] = r - 1; 
        }

        // 3. Precompute Sparse Table for Binary Lifting
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }

        // 4. Process queries
        vector<int> ans;
        for (const auto& q : queries) {
            int u = original_to_sorted[q[0]];
            int v = original_to_sorted[q[1]];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) swap(u, v); // Ensure u is always to the left

            // Check reachability: can u ever reach or pass v?
            int max_reach = u;
            for (int j = LOG - 1; j >= 0; --j) {
                max_reach = up[max_reach][j];
            }
            if (max_reach < v) {
                ans.push_back(-1);
                continue;
            }

            // Count the steps using binary lifting
            int steps = 0;
            int curr = u;
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[curr][j] < v) {
                    curr = up[curr][j];
                    steps += (1 << j);
                }
            }
            
            // One final jump takes us to or past v
            ans.push_back(steps + 1);
        }

        return ans;
    }
};