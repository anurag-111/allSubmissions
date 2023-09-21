// https://leetcode.com/problems/root-equals-sum-of-children

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
    bool isSum(TreeNode* node) {
        if (node == NULL || (node->left == NULL && node->right == NULL)) {
            return true;
        }
        
        int childrenValue = 0;
        if (node->left != NULL) {
            childrenValue += node->left->val;
        }
        if (node->right != NULL) {
            childrenValue += node->right->val;
        }
        
        return (node->val == childrenValue) && checkTree(node->left) && checkTree(node->right);
    }
    
public:
    // Function to check whether all nodes of a tree have the value 
    // equal to the sum of their child nodes.
    bool checkTree(TreeNode* root) {
        return isSum(root);
    }
};
