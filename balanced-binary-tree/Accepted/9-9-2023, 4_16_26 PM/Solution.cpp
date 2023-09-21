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
private:
    int isBST(TreeNode *root, bool &flag) {
        // Base condition
        if(root == NULL) {
            return -1;
        }

        // Recursive calls
        int leftHeight = isBST(root -> left, flag);
        int rightHeight = isBST(root -> right, flag);

        // Condition check
        if(abs(leftHeight - rightHeight) > 1) {
            flag = false;
        }

        // Return statement
        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        if(root == NULL) {
            return true;
        }

        isBST(root, flag);
        return flag;
    }
};