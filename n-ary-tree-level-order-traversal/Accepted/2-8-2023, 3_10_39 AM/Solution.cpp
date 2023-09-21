// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private: 
    vector<vector<int>> ans;

    void helper(Node* node, int level) {
        if (level == size(ans)) {
            ans.push_back({node->val});
        } else {
            ans[level].push_back(node->val);
        }
        for (Node* child : node->children) {
            helper(child, level + 1);
        }
    }
    

public :
    vector<vector<int>> levelOrder(Node* root) {
        if (!root){
            return {};
        }
        helper(root, 0);
        return ans;
    }
    

};