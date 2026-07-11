class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& vertexCount, int& edgeSum) {
        visited[node] = true;
        vertexCount++;
        edgeSum += adj[node].size(); // Add the degree of the current vertex
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertexCount, edgeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int completeComponentsCount = 0;
        
        // Step 2: Iterate through all nodes to find each component
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertexCount = 0;
                int edgeSum = 0;
                
                // Traverse the component
                dfs(i, adj, visited, vertexCount, edgeSum);
                
                // Step 3: Check if the component is complete
                if (edgeSum == vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};