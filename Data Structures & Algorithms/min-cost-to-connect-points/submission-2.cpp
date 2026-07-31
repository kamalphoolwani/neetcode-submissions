class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int edgesUsed = 0;
        int mstCost = 0;
        
        // visited[i] = true if node i is already in our MST
        vector<bool> visited(n, false);
        
        // Priority Queue stores pairs of {cost, node_index}
        // Using greater to make it a Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Start with node 0, cost 0
        pq.push({0, 0});
        
        while (edgesUsed < n) {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // If node u is already in MST, skip it
            if (visited[u]) continue;
            
            // Add node to MST
            visited[u] = true;
            mstCost += cost;
            edgesUsed++;
            
            // Explore all neighbors of u
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + 
                               abs(points[u][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }
        
        return mstCost;
    }
};