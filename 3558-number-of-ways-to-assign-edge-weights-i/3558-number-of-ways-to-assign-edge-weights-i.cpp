class Solution {
private:
    int max_depth = 0;

    // DFS helper to find the maximum depth from the root
    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
        max_depth = max(max_depth, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj);
            }
        }
    }

    // Helper for fast modular exponentiation: (base^exp) % mod
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        // Step 1: Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Find the maximum depth (k)
        max_depth = 0;
        dfs(1, 0, 0, adj); // Start at node 1, parent 0, initial depth 0
        
        // Step 3: Return 2^(max_depth - 1) % (10^9 + 7)
        long long MOD = 1e9 + 7;
        return power(2, max_depth - 1, MOD);
    }
};