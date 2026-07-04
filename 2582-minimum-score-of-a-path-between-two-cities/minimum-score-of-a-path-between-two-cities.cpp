class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        int min_score = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        
        // Start Breadth-First Search (BFS) from city 1
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (const auto& neighbor : adj[node]) {
                int next_node = neighbor.first;
                int weight = neighbor.second;
                
                // Update the minimum road score found so far
                min_score = min(min_score, weight);
                
                if (!visited[next_node]) {
                    visited[next_node] = true;
                    q.push(next_node);
                }
            }
        }
        
        return min_score;
    }
};