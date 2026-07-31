class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int i) {
        if(parent[i] == i) return i;
        return parent[i] = findParent(parent[i]);
    }

    bool unite(int i, int j) {
        int rootI = findParent(i);
        int rootJ = findParent(j);

        if(rootI != rootJ) {
            if(size[rootI] > size[rootJ]) {
                parent[rootJ] = rootI;
                size[rootI] += size[rootJ];
            } else {
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
        edges.reserve(n * (n - 1) / 2); // Optimization

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({d, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU d(n);
        int ans = 0;
        int edgesUsed = 0;

        for(int i = 0; i < edges.size() && edgesUsed < n - 1; i++) {
            if(d.unite(edges[i][1], edges[i][2])) {
                ans += edges[i][0];
                edgesUsed++; // Optimization: Stop once we have n-1 edges
            }
        }

        return ans;
    }
};