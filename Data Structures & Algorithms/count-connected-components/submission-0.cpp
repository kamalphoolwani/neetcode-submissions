class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        int connected = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                connected++;
                dfs(i, adj, vis);
            }
        }

        return connected;
    }
};
