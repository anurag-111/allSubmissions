// https://leetcode.com/problems/n-ary-tree-postorder-traversal

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
public:
    void traversal(Node *root, vector<int> &post_order) {
        // base condition
        if(root == NULL) {
            return;
        }

        // traversing in postorder style
        for(auto node : root->children) {
            traversal(node, post_order);
        }

        // inserting the elements
        post_order.push_back(root->val);
    }

    vector<int> postorder(Node *root) {
        vector<int> post_order;
        traversal(root, post_order);
        return post_order;
    }
};
















