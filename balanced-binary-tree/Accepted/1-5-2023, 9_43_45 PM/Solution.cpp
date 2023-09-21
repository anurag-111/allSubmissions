// https://leetcode.com/problems/balanced-binary-tree

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
public:
    bool isBalanced(TreeNode* root) {
        return balance_check(root) != -1;
    }
    
    int balance_check(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int left_height = balance_check(root->left);
        if (left_height == -1) {
            return -1;
        }
        
        int right_height = balance_check(root->right);
        if (right_height == -1) {
            return -1;
        }
        
        if (abs(left_height - right_height) > 1) {
            return -1;
        }
        
        return max(left_height, right_height) + 1;
    }
};

// TC : O(n)
// SC : O(n)