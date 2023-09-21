// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    // Helper function for performing inorder traversal of the tree
    void inorderTraversalHelper(TreeNode* root, vector<int>& nodes) {
        // Base case: If the current node is NULL, return
        if (root == NULL) {
            return;
        }
        
        // Recursive call to traverse the left subtree
        inorderTraversalHelper(root->left, nodes);
        
        // Add the current node's value to the list
        nodes.push_back(root->val);
        
        // Recursive call to traverse the right subtree
        inorderTraversalHelper(root->right, nodes);
    }
    
public:
    // Function to return a vector containing the values of nodes in inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        // Call the helper function to perform inorder traversal
        inorderTraversalHelper(root, nodes);
        
        return nodes;
    }
};