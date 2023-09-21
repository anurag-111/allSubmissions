// https://leetcode.com/problems/insert-into-a-binary-search-tree

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root == NULL) {
             return new TreeNode(val);
         }
         
         TreeNode *current = root;
         
         if(val > current -> val) {
             current -> right = insertIntoBST(current -> right, val);
         } else {
             current -> left = insertIntoBST(current -> left, val);
         }

         return root;
    }
};