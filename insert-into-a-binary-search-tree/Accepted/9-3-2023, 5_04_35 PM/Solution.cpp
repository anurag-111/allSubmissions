// https://leetcode.com/problems/insert-into-a-binary-search-tree

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root == NULL) {
             return new TreeNode(val);
         }
         
         TreeNode *current = root;
         
         while(current) {
             if(val > current -> val) {
                 if(current -> right == NULL) {
                     current -> right = new TreeNode(val);
                     break;
                 }
                 current = current -> right;
             } else {
                 // val < root -> data
                 if(current -> left == NULL) {
                     current -> left = new TreeNode(val);
                     break;
                 }
                 current = current -> left;
             }
         }
         return root;
    }
};