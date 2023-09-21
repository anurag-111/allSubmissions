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
           
        
        unordered_map<Node*,Node*> mp;
        Node *clone = new Node(node->val);
        mp[node] = clone;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            for(Node *neigh: cur->neighbors) {
                
                if(mp.find(neigh)==mp.end()) {
                    mp[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                mp[cur]->neighbors.push_back(mp[neigh]);
                
            }
        }
        
        return mp[node];
    }
};