// https://leetcode.com/problems/minimum-depth-of-binary-tree

// DFS APPROACH : 
class Solution {
    private:
        int traversal(TreeNode* root) {
            if(root == NULL) {
                return 0;
            }
            
            if(root->left == NULL && root->right == NULL) {
                return 1;
            }

            int leftVal = INT_MAX;
            int rightVal = INT_MAX;

            if(root->left) {
                leftVal = traversal(root->left);
            }

            if(root->right) {
                rightVal = traversal(root->right);
            }

            return min(leftVal, rightVal) + 1;
        }
    
    public:
        int minDepth(TreeNode* root) {
            return traversal(root);
        }
};

// Time complexity : O(N)
// Space complexity : O(H)