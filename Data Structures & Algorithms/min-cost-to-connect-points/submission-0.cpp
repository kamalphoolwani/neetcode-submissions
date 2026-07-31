class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int i){
        if(parent[i]==i)
            return i;
        return parent[i] = findParent(parent[i]);
    }

    bool unite(int i, int j){
        int rootI = findParent(i);
        int rootJ = findParent(j);

        if(rootI!=rootJ){
            if(size[rootI]>size[rootJ]){
                parent[rootJ] = rootI;
                size[rootI] += size[rootJ];
            }
            else{
                parent[rootI] = rootJ;
                size[rootJ] += size[rootI];
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
       vector<array<int, 3>> edges;

        for(int i = 0; i<n; i++){
            for(int j=i+1; j<n; j++){
               int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
               edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        DSU d(n);
        int ans = 0;
        for(int i = 0; i<edges.size(); i++){
            int dist =  edges[i][0];
            int node1 = edges[i][1];
            int node2 = edges[i][2];
            if(d.unite(node1, node2))
                ans += dist;
        }

        return ans;

    }
};
