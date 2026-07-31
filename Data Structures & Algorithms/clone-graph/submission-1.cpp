/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Map to store cloned nodes and track visited status
        unordered_map<Node*, Node*> mp;
        
        // Clone the starting node and push to queue
        Node* clone = new Node(node->val);
        mp[node] = clone;
        
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Process all neighbors of the current original node
            for (Node* neighbor : curr->neighbors) {
                // If neighbor hasn't been cloned yet
                if (mp.find(neighbor) == mp.end()) {
                    // 1. Clone the neighbor
                    mp[neighbor] = new Node(neighbor->val);
                    // 2. Add the original neighbor to queue to process its connections later
                    q.push(neighbor);
                }
                // Connect the cloned neighbor to the cloned current node
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
        }
};
