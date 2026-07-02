class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions for moving up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // maxHealth[i][j] stores the maximum health we can have when reaching cell (i, j)
        vector<vector<int>> maxHealth(m, vector<int>(n, -1));
        
        // Priority queue stores {remaining_health, row, col}
        // We want to maximize health, so we use a max-heap (default in C++)
        priority_queue<tuple<int, int, int>> pq;
        
        // Initialize starting position
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        
        maxHealth[0][0] = startHealth;
        pq.push({startHealth, 0, 0});
        
        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();
            
            // If we reached the destination with positive health, return true
            if (r == m - 1 && c == n - 1 && h >= 1) {
                return true;
            }
            
            // If we found a path to this cell with more health already, skip
            if (h < maxHealth[r][c]) continue;
            
            // Explore neighbors
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                // Check boundaries
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nextHealth = h - grid[nr][nc];
                    
                    // We only move if the next cell results in a positive health 
                    // AND it's better than any health value we've achieved there so far
                    if (nextHealth > 0 && nextHealth > maxHealth[nr][nc]) {
                        maxHealth[nr][nc] = nextHealth;
                        pq.push({nextHealth, nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
};