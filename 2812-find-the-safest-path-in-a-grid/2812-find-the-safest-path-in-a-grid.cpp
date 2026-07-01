class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end cell has a thief, the safeness factor is automatically 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        // dist[r][c] will store the minimum Manhattan distance to any thief
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Phase 1: Multi-Source BFS to calculate cell safeness
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Phase 2: Max-Heap BFS (Dijkstra-like) to find the maximum safeness path
        // Priority Queue stores: {safeness_factor, r, c}
        priority_queue<vector<int>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({dist[0][0], 0, 0});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int max_safe = curr[0];
            int r = curr[1];
            int c = curr[2];

            // If we reached the bottom-right corner, return the accumulated maximum safeness
            if (r == n - 1 && c == n - 1) {
                return max_safe;
            }

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The safeness of the path to the neighbor is limited by the minimum along the way
                    int next_safe = min(max_safe, dist[nr][nc]);
                    pq.push({next_safe, nr, nc});
                }
            }
        }

        return 0;
    }
};