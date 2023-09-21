// https://leetcode.com/problems/minimum-distance-between-bst-nodes

// val, left, right
class Solution {
    private:
        int calculateDiff(TreeNode *root, int &currDiff, int &maxDiff) {
            if(root == NULL) {
                return 0;
            }

            int leftVal = calculateDiff(root -> left, currDiff, maxDiff);
            int rightVal = calculateDiff(root -> right, currDiff, maxDiff);

            if(root -> left != NULL && root -> right != NULL) {
                int minVal = min(root -> val - leftVal, root -> val - rightVal);
                currDiff = min(minVal, abs(leftVal - rightVal));
                maxDiff = min(maxDiff, currDiff);
            }

            return root -> val;
        }
    public:
        int minDiffInBST(TreeNode* root) {
            // Empty tree
            if(root == NULL) { 
                return 0;
            }

            int currDiff = 0;
            int minDiff = INT_MAX;

            // Helper Function 
            calculateDiff(root, currDiff, minDiff);

            // Return the result
            return minDiff;
        }
};