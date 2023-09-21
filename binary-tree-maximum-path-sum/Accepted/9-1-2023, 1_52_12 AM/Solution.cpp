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

            // Handles the cases : root + max(left, right) OR only the root
            // should be returned from the current node
            int maxToReturn = max(root-> val + maxLeftOrRight, root->val);

            // Handles the case when the current traversed path is itself
            // the max path otheriwse update with the maximum path.
            int currentPathSum = max(root->val + left + right, maxToReturn);

            // Update the result
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