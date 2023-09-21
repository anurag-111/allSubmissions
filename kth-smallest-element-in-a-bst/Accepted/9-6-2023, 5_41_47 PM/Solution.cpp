// https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
private:
    void findInorder(TreeNode *root, vector<int> &inorderTraversal) {
        if(root == NULL) {
            return;
        }

        findInorder(root -> left, inorderTraversal);
        inorderTraversal.push_back(root -> val);
        findInorder(root -> right, inorderTraversal);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderTraversal;
        findInorder(root, inorderTraversal);

        // For printing the inorder traversal
        // for(int num : inorderTraversal) {
        //     cout << num << " ";
        // }

        return inorderTraversal[k - 1];        
    }
};