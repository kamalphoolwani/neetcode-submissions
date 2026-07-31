class Solution {
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,
                      greater<pair<int, pair<int,int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];    
        while(!pq.empty()){
            int currTime = pq.top().first;
            int cX = pq.top().second.first;
            int cY = pq.top().second.second;
            pq.pop();
            if(currTime > dist[cX][cY])
                continue;
            
            if(cX==(n-1) and cY == (n-1))
                return currTime;
            
            for(int i = 0; i<4; i++){
                int nX = cX + dirX[i];
                int nY = cY + dirY[i];
                if(nX>=0 and nX<n and nY>=0 and nY<n){
                    int nextTime = max(currTime, grid[nX][nY]);
                    if(nextTime < dist[nX][nY])
                    {
                        dist[nX][nY] = nextTime;
                        pq.push({nextTime, {nX, nY}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
