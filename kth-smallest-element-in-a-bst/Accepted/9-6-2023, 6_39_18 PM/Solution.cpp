// https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
private:
    void findNode(TreeNode *root, int k, int &count, TreeNode *&kthSmallest) {
        if(root == NULL) {
            return;
        }

        findNode(root -> left, k, count, kthSmallest);
        
        count++;
        if(count == k) {
            kthSmallest = root;
            return;
        }

        findNode(root -> right, k, count, kthSmallest);
    }
public:
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        TreeNode *kthSmallest = NULL;
        findNode(root, k, count, kthSmallest);
        return kthSmallest -> val;
    }
};