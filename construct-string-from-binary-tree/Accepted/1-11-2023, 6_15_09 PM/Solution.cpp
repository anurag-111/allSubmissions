// https://leetcode.com/problems/construct-string-from-binary-tree

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
    stringstream ans;

public:
    string tree2str(TreeNode* root) {
        buildStr(root);
        return ans.str();
    }

    void buildStr(TreeNode* root) {
        ans << root->val;

        if(root->left == NULL && root->right == NULL) {
            return;
        }

        ans << '(';
        if (root->left != NULL) {
            buildStr(root->left);
        }
        ans << ')';

        if (root->right != NULL) {
            ans << '(';
            buildStr(root->right);
            ans << ')';
        }
    }
};












