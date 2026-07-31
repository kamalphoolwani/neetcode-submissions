class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // We run k+1 times because k stops = k+1 edges
        for(int i = 0; i <= k; i++) {
            // Create a copy to avoid using updated values from the current iteration
            vector<int> tmpDist = dist; 
            
            for(auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];
                
                // Only update if the source was reachable in the PREVIOUS iteration
                if(dist[u] != INT_MAX && dist[u] + cost < tmpDist[v]) {
                    tmpDist[v] = dist[u] + cost;
                }
            }
            dist = tmpDist; // Update the main dist array after the full layer
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
