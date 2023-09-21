// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
    private:
        int solve(TreeNode *root, int &maxPathSum) {
            if(root == NULL) {
                return 0;
            }

            int left = solve(root -> left, maxPathSum);
            int right = solve(root -> right, maxPathSum); 

            int maxLeftOrRight = max(left, right);

            int maxToReturn = max(root->val, root->val + maxLeftOrRight);
            int currentPathSum = max(root->val + left + right, maxToReturn);
            maxPathSum = max(maxPathSum, currentPathSum);

            return maxToReturn;
        }
    public:
        int maxPathSum(TreeNode* root) {
            int maxPathSum = 0;
            solve(root, maxPathSum);
            return maxPathSum;
        }
};