class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n+1);
        for(int i = 0; i<=n; i++)
            parent[i] = i;
    }

    int findParent(int i){
        if(parent[i]==i)
            return i;
        return parent[i] = findParent(parent[i]);
    }

    bool unite(int node1, int node2){
        int pNode1 = findParent(node1);
        int pNode2 = findParent(node2);
        if(pNode1 != pNode2){
            parent[pNode2] = pNode1;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& edge : edges) {
            // If unite returns false, these two nodes already share a parent
            if (!dsu.unite(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
