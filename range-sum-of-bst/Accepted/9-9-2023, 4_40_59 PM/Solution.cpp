// https://leetcode.com/problems/range-sum-of-bst

// val, left, right
class Solution {
private:
    void sumBST(TreeNode* root, int low, int high, int &sum) {
        if(root == NULL) {
            return;
        }

        sumBST(root -> left, low, high, sum);
        sumBST(root -> right, low, high, sum);

        if(root -> val >= low && root -> val <= high) {
            sum += root -> val;
        } 
        return;     
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        sumBST(root, low, high, sum);
        return sum;
    }
};