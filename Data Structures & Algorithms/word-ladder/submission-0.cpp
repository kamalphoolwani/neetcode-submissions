class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        
        // Use a level-order BFS
        int steps = 1; 

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return steps;

                // Try all possible 1-letter transformations
                for (int j = 0; j < curr.size(); j++) {
                    char orig = curr[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        curr[j] = ch;
                        if (st.count(curr)) {
                            q.push(curr);
                            st.erase(curr); // Mark as visited so we don't loop
                        }
                    }
                    curr[j] = orig; // Backtrack character
                }
            }
            steps++;
        }
        return 0;
    }
};
