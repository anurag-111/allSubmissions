// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
private:
    int solve(TreeNode *root, int &maxPathSum) {
        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left, maxPathSum);
        int right = solve(root->right, maxPathSum);

        int maxLeftOrRight = max(left, right);

        // Calculate the maximum value that can be returned from the current node
        int maxToReturn = max(root->val + maxLeftOrRight, root->val);

        // Calculate the maximum path sum considering the path through the current node
        int currentPathSum = max(root->val + left + right, maxToReturn);

        // Update the overall maximum path sum found so far
        maxPathSum = max(maxPathSum, currentPathSum);

        return maxToReturn;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = root->val;
        solve(root, maxPathSum);
        return maxPathSum;
    }
};
