// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    // Helper function for performing preorder traversal of the tree
    void performPreorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        
        // Add the current node's value to the list
        nodes.push_back(root->val);
        
        // Recursively perform preorder traversal on the left subtree
        performPreorderTraversal(root->left, nodes);
        
        // Recursively perform preorder traversal on the right subtree
        performPreorderTraversal(root->right, nodes);
    }
    
public:
    // Function to return a vector containing the values of nodes in preorder traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        // Call the helper function to perform the traversal
        performPreorderTraversal(root, nodes);
        
        return nodes;
    }
};