class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;
        
        // Locate starting point and all litter positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int k = litters.size();
        int targetMask = (1 << k) - 1;
        if (targetMask == 0) return 0; // No litter to collect
        
        // Map litter coordinates to bitmask indices
        auto getLitterIndex = [&](int r, int c) -> int {
            for (int i = 0; i < k; ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };
        
        // best_energy[r][c][mask] records the maximum energy seen for each state
        vector<vector<vector<int>>> best_energy(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );
        
        // Queue elements: {row, col, mask, energy, steps}
        queue<tuple<int, int, int, int, int>> q;
        q.push({startR, startC, 0, energy, 0});
        best_energy[startR][startC][0] = energy;
        
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c, mask, e, steps] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                // Check bounds and obstacle
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int nextE = e - 1;
                if (nextE < 0) continue;
                
                int nextMask = mask;
                char cell = classroom[nr][nc];
                
                if (cell == 'L') {
                    int idx = getLitterIndex(nr, nc);
                    if (idx != -1) nextMask |= (1 << idx);
                }
                
                // Target condition reached
                if (nextMask == targetMask) {
                    return steps + 1;
                }
                
                // Reset energy if stepping on 'R'
                if (cell == 'R') {
                    nextE = energy;
                }
                
                // If energy is depleted and not at 'R', cannot make any further moves
                if (nextE == 0) continue;
                
                // Prune states with inferior energy
                if (nextE > best_energy[nr][nc][nextMask]) {
                    best_energy[nr][nc][nextMask] = nextE;
                    q.push({nr, nc, nextMask, nextE, steps + 1});
                }
            }
        }
        
        return -1;
    }
};