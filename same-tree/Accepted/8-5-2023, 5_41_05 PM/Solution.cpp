// https://leetcode.com/problems/same-tree

class Solution {
private:
    bool helper(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, they are equal
        if(root1 == NULL && root2 == NULL) {
           return true;
        }
        
        // If one of the nodes is null but the other is not, they are not equal
        if(root1 == NULL || root2 == NULL) {
           return false;
        }
        
        // If the values of the current nodes are different, they are not equal
        if(root1->val != root2->val) {
            return false;
        } 
        
        return helper(root1->left, root2->left) && helper(root1->right, root2->right);
        
    }
        
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};