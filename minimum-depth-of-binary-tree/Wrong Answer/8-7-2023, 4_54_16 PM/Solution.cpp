// https://leetcode.com/problems/minimum-depth-of-binary-tree

// DFS APPROACH : 
class Solution {
    private:
        int traversal(TreeNode* root, int depth) {
            if(root->left == NULL && root->right == NULL) {
                return depth;
            }

            int leftVal = INT_MAX;
            int rightVal = INT_MAX;

            if(root->left) {
                leftVal = traversal(root->left, ++depth);
            }

            if(root->right) {
                rightVal = traversal(root->right, ++depth);
            }

            return min(leftVal, rightVal);
        }
    
    public:
        int minDepth(TreeNode* root) {
            if(root == NULL) {
                return 0;
            }

            int depth = 0;
            return traversal(root, depth) + 1;
        }
};

// Time complexity : O(N)
// Space complexity : O(H)