// https://leetcode.com/problems/delete-node-in-a-bst

// val, left, right

class Solution {

private:
    TreeNode* inorderSuccessor(TreeNode* root) {
        while(root != NULL && root -> left != NULL) {
            root = root -> left;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(key < root -> val) {
            root -> left = deleteNode(root -> left, key);
        } else if(key > root -> val) {
            root -> right = deleteNode(root -> right, key);
        } else {
            if(root -> left == NULL && root -> right == NULL) {
                // Case 1 : When there are no children
                delete root;
                return NULL;
            }
            
            if(root -> left != NULL && root -> right == NULL) {  
                // Case 2 : When the left child exists
                TreeNode *temp = root;
                root = root -> left;
                delete temp;
            } else if(root -> left == NULL && root -> right != NULL) { 
                // Case 3 : When the right child exists
                TreeNode *temp = root;
                root = root -> right;
                delete temp;
            } else {
                // Case 4 : When both the left and right node exists
                // Find the inorderSuccessor of the node to be deleted
                TreeNode *inorderSucc = inorderSuccessor(root -> right);
                root -> val = inorderSucc -> val;
                root -> right = deleteNode(root -> right, inorderSucc -> val);
            }
        }
        return root;
    }
};