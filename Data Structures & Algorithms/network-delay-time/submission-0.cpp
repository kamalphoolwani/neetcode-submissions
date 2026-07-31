class Solution {
    const int inf = 1e8;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto &edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n+1, inf);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node])
                continue;
            
            for(auto &neigh: adj[node]){
                int nNode = neigh.first;
                int wt = neigh.second;

                if((d + wt) < dist[nNode]){
                    dist[nNode] = d + wt;
                    pq.push({dist[nNode], nNode});
                }
            }
        }

        int maxm = INT_MIN;

        for(int i = 1; i<=n; i++){
            if(dist[i]==inf)
                return -1;
            maxm = max(dist[i], maxm);
        }

        return maxm;

    }
};
