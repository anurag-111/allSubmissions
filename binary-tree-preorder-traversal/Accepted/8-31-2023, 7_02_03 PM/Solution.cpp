// https://leetcode.com/problems/binary-tree-preorder-traversal

// val, left, right
class Solution {
    public :
        vector<int> preorderTraversal(TreeNode* root) {
            TreeNode* current = root;
            vector<int> nodes;

            while(current) {
                if(current->left) {
                    // Find the inorder predecessor of the current node
                    TreeNode *pred = current->left;
                    while(pred->right && pred->right != current) {
                        pred = pred->right;
                    }
                    if(pred->right == NULL) {
                        nodes.push_back(current->val);
                        pred->right = current;
                        current = current->left;
                    } else {
                        pred->right = NULL;
                        current = current->right;
                    }
                } else {
                    nodes.push_back(current->val);
                    current = current->right;
                }
            } 
            return nodes;
        }
};
