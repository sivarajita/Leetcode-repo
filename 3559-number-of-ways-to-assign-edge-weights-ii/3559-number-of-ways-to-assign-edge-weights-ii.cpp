class Solution {
    private:
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;
    long long MOD = 1e9 + 7;

    // Helper function to precompute powers of 2
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // DFS to populate depths and immediate parents (2^0 ancestor)
    void dfs(int node, int parent, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        for (int i = 1; i < LOG; ++i) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Function to find LCA using Binary Lifting
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Bring both nodes to the same level
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Lift both nodes simultaneously right below their LCA
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        // Initialize tree traversal starting from root node 1
        dfs(1, -1, 0, adj);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int k = depth[u] + depth[v] - 2 * depth[lca];

            // Number of ways is 2^(k - 1) % MOD
            answer.push_back(power(2, k - 1));
        }
        return answer;
    }
};