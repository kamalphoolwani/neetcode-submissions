class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        // Initialize inDegree for all unique characters
        for (const string& w : words) {
            for (char c : w) inDegree[c] = 0;
        }

        // Build Graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            // Check prefix edge case
            if (w1.size() > w2.size() && w1.compare(0, w2.size(), w2) == 0) return "";
            
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    break; // Only the first differing character defines the order
                }
            }
        }

        // Kahn's BFS
        queue<char> q;
        for (auto const& [ch, degree] : inDegree) {
            if (degree == 0) q.push(ch);
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        // Cycle Check
        return (result.size() == inDegree.size()) ? result : "";
    }
};
