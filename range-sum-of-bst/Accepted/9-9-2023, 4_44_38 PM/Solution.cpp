// https://leetcode.com/problems/range-sum-of-bst

class Solution {
private:
    void calculateSumInRange(TreeNode* root, int low, int high, int &sum) {
        if (root == nullptr) {
            return;
        }

        calculateSumInRange(root->left, low, high, sum);
        calculateSumInRange(root->right, low, high, sum);

        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        calculateSumInRange(root, low, high, sum);
        return sum;
    }
};
