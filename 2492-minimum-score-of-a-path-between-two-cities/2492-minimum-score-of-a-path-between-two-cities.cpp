class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto& road : roads){
            int u=road[0];
            int v=road[1];
            int weight=road[2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
            queue<int> q;
            vector<bool> visited(n+1,false);
            q.push(1);
            visited[1]=true;
            int min_score=INT_MAX;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(const auto& neighbor : adj[curr]){
                    int next_node=neighbor.first;
                    int weight=neighbor.second;
                    min_score=min(min_score,weight);
                    if(!visited[next_node]){
                        visited[next_node]=true;
                        q.push(next_node);
                    }
                }
            }
            return min_score;
        
    }
};