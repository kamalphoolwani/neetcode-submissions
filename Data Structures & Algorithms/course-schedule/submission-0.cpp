class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto &itr: prerequisites){
            adj[itr[1]].push_back(itr[0]);
            inDegree[itr[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        int courseDone = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            courseDone++;

            for(auto &neigh: adj[node]){
                inDegree[neigh]--;
                if(inDegree[neigh]==0)
                    q.push(neigh);
            }
        }

        return courseDone==numCourses;
    }
};
