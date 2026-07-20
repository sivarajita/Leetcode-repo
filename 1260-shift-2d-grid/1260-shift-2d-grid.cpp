class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        // Optimize k to prevent redundant full rotations
        k = k % totalElements;
        
        // Initialize a new grid with the same dimensions
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Calculate the new flattened 1D position
                int new1DIndex = (r * n + c + k) % totalElements;
                
                // Convert the 1D position back to 2D coordinates
                int new_r = new1DIndex / n;
                int new_c = new1DIndex % n;
                
                // Assign the value to the new position
                result[new_r][new_c] = grid[r][c];
            }
        }
        
        return result;
    }
};