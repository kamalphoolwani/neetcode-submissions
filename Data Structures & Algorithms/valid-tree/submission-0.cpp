class Solution {
public:
    bool dfs(int node, int par, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;

        for(auto &neigh : adj[node]){
            if(vis[neigh]==false){
                if(dfs(neigh, node, adj, vis)==false)
                    return false;
            }
            else if(neigh != par)
                return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(dfs(0, -1, adj, vis)==false)
            return false;
        
        for(int i = 0; i<n; i++){
            if(vis[i]==false)
                return false;
        }
        return true;
    }
};
