class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        std::vector<bool> visited(n,false);
        int completecomponentscount=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int nodecount=0;
                int edgecount=0;
                dfs(i,adj,visited,nodecount,edgecount);
                int actualedges=edgecount/2;
                int requirededges=(nodecount*(nodecount-1)) / 2;
                if(actualedges==requirededges){
                    completecomponentscount++;
                }
            }

        }
        return completecomponentscount;
    }
    private:
    void dfs(int node,const std::vector<std::vector<int>>& adj,std::vector<bool>& visited, int& nodecount, int& edgecount){
        visited[node]=true;
        nodecount++;
        edgecount+=adj[node].size();
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor,adj,visited,nodecount,edgecount);
            }
        }
    }
};