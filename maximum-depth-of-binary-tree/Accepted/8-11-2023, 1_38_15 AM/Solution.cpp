// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftVal = dfs(root->left);
        int rightVal = dfs(root->right);

        return 1 + max(leftVal, rightVal);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        return dfs(root);
    }
};