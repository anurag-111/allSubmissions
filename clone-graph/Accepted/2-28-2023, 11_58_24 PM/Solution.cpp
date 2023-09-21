// https://leetcode.com/problems/clone-graph

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
        if(!node) {
            return node;
        }

        // Creating a map for the mapping of the deep copy of nodes
        unordered_map<Node*, Node*> map;
        Node* clone = new Node(node->val);
        map[node] = clone;

        // Creating a queue for the neighbouring edges
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for(Node* neigh : cur->neighbors) {
                
                // Insert the neighbors if not already present
                if(map.find(neigh) == map.end()) {     
                    map[neigh] = new Node(neigh->val); 
                    q.push(neigh);
                }

                // Connection of the neighboring edges
                map[cur]->neighbors.push_back(map[neigh]);
            }
        }

        // Returning the copy of the given node which 
        // was a  reference to the cloned graph.
        return map[node];
    }
};


















