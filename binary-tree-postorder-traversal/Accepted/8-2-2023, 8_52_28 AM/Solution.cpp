// https://leetcode.com/problems/binary-tree-postorder-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    // Helper function for performing postorder traversal of the tree
    void postorderTraversalHelper(TreeNode* root, vector<int>& nodes) {
        // Base case: If the current node is NULL, return
        if (root == NULL) {
            return;
        }
        
        // Recursive call to traverse the left subtree
        postorderTraversalHelper(root->left, nodes);
        
        // Recursive call to traverse the right subtree
        postorderTraversalHelper(root->right, nodes);
        
        // Add the current node's value to the list
        nodes.push_back(root->val);
    }
    
public:
    // Function to return a vector containing the values of nodes in postorder traversal
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        // Call the helper function to perform postorder traversal
        postorderTraversalHelper(root, nodes);
        
        return nodes;
    }
};



