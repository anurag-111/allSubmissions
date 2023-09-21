// https://leetcode.com/problems/symmetric-tree

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
    bool helper(TreeNode* leftSubTree, TreeNode* rightSubTree) {
        // Mirror NULL nodes
        if(leftSubTree == NULL && rightSubTree == NULL) {
            return true;
        }
        
        // When one of the nodes is null
        if(!leftSubTree || !rightSubTree) {
            return false;
        }
        
        // When values differ
        if(leftSubTree->val != rightSubTree->val) {
            return false;
        }
        
        return helper(leftSubTree->left, rightSubTree->right) && helper(leftSubTree->right, rightSubTree->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};