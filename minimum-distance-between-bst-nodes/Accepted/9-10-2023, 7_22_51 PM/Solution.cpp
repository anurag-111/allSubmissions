// https://leetcode.com/problems/minimum-distance-between-bst-nodes

class Solution {
private:
    void calculate(TreeNode *root, int &minDiff, TreeNode *&prevNode) {
        if(root == NULL) {
            return;
        }

        calculate(root -> left, minDiff, prevNode);

        if(prevNode) {
            int currDiff = (root -> val - prevNode -> val);
            minDiff = min(minDiff, currDiff);
        }

        prevNode = root;
        calculate(root -> right, minDiff, prevNode);
    }
public:
    int minDiffInBST(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int minDiff = INT_MAX;
        TreeNode *prevNode = NULL;
        calculate(root, minDiff, prevNode);
        return minDiff;
    }
};