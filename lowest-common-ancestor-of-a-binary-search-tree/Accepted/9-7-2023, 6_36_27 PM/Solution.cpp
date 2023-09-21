// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(root -> val > p -> val && root -> val > q -> val) {
                // Left sub-tree
                root = root -> left;
            } else if(root -> val < p -> val && root -> val < q -> val) {
                // Right sub-tree
                root = root -> right;
            } else {
                // Found the LCA
                return root;
            }
        }
        return NULL;
    }
};