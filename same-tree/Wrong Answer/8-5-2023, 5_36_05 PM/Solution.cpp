// https://leetcode.com/problems/same-tree

class Solution {
private:
    bool helper(TreeNode* root1, TreeNode* root2) {
        if(root1->val != root2->val) {
            return false;
        } else {
            return true;
        }
        
        return helper(root1->left, root2->left) && helper(root1->right, root2->right);
        
        
    }
        
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};