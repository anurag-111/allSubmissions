// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

// val, left, right
class Solution {
private:
    void calculateInorder(TreeNode *root, vector<int> &inorderTraversal) {
        if(root == NULL) {
            return;
        }

        calculateInorder(root -> left, inorderTraversal);
        inorderTraversal.push_back(root -> val);
        calculateInorder(root -> right, inorderTraversal);
    }
public:
    bool findTarget(TreeNode *root, int k) {
        // 1. Find the inorder traversal of the tree
        vector<int> inorderTraversal;
        calculateInorder(root, inorderTraversal);

        // for(int num : inorderTraversal) {
        //     cout << num << " ";
        // }

        // 2. Apply two pointer approach
        int i = 0;
        int j = inorderTraversal.size() - 1;
        while(i <= j) {
            int sum = inorderTraversal[i] + inorderTraversal[j];
            if(sum == k) {
                return true;
            } else if(sum > k) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
};