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
    void cloneHelper(Node* currNode, Node *cloneNode,  unordered_map<Node*, Node*> &mp){
        mp[currNode] = cloneNode;
        for(auto &itr : currNode->neighbors){
            if(mp.find(itr) == mp.end()){
                Node *temp = new Node(itr->val);
                cloneHelper(itr, temp, mp);
            }
            cloneNode->neighbors.push_back(mp[itr]);
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        Node* cloneNode = new Node(node->val);
        unordered_map<Node*, Node*> mp;  // saves the original node mapping to current created node
        cloneHelper(node, cloneNode, mp);
        return cloneNode;
    }
};
