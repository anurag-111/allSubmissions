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
    // This function calculates the sum of values in a tree.
    int sum(TreeNode* node) {
        if (node == NULL) {
            return 0; // If the node is empty, its sum is 0.
        }
        
        // If the node is not empty, add its value to the sum of its left and right children.
        return node->val + sum(node->left) + sum(node->right);
    }
    
public:
    // This function checks if a tree satisfies a specific condition.
    bool checkTree(TreeNode* root) {
        if (root == NULL) {
            return true; // An empty tree automatically satisfies the condition.
        }
        
        int rootValue = root->val; // Get the value of the root node.
        
        // Calculate the sum of values of the left and right children.
        int childrenValue = sum(root->left) + sum(root->right);
        
        // Compare the value of the root node with the sum of its children's values.
        // If they are equal, then the condition is satisfied, and we return true.
        return rootValue == childrenValue;
    }
};
