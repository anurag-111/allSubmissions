// https://leetcode.com/problems/diameter-of-binary-tree

class Solution {
private:
    int diameter;

    int dfs(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int leftVal = dfs(root->left);
        int rightVal = dfs(root->right);

        diameter = max(diameter, (leftVal + rightVal));

        return 1 + max(leftVal, rightVal);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        diameter = 0;
        dfs(root);
        return diameter;
    }
};