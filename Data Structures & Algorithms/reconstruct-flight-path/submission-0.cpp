class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string airport){
        while(!adj[airport].empty()){
            string next = adj[airport].top();
            adj[airport].pop();
            dfs(next);
        }
        result.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &itr : tickets)
            adj[itr[0]].push(itr[1]);
        
        dfs("JFK");

        reverse(result.begin(), result.end());
        return result;
    }
};
