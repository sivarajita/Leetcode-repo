class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        // Sort restrictions by building ID
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // 2. Left-to-Right Pass
        for (int i = 1; i < m; ++i) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + dist);
        }
        
        // 3. Right-to-Left Pass
        for (int i = m - 2; i >= 0; --i) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + dist);
        }
        
        // 4. Calculate max height between consecutive restricted buildings
        int max_height = 0;
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
            
            int peak = (h1 + h2 + (id2 - id1)) / 2;
            max_height = max(max_height, peak);
        }
        
        return max_height;
    }
};