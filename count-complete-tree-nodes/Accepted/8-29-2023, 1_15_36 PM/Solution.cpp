// https://leetcode.com/problems/count-complete-tree-nodes

// val, left, right

class Solution {
private:
    int traverseLeft(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root -> left;
        }
        
        return height;      
    }
    
    int traverseRight(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root -> right;
        }
        
        return height;      
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int leftHeight = traverseLeft(root);
        int rightHeight = traverseRight(root);
        
        if(leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};