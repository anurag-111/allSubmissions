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
            // Case 1 : When there are no children
            if(root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2 : When the left child exists
            if(root -> left != NULL && root -> right == NULL) {
                TreeNode *temp = root -> left;
                delete root -> left;
                return temp;
            }

            // Case 3 : When the right child exists
            if(root -> left == NULL && root -> right != NULL) {
                TreeNode *temp = root -> right;
                delete root -> right;
                return temp;
            }

            // Case 4 : When both the left and right node exists
            // Find the inorderSuccessor of the node to be deleted

            TreeNode *inorderSucc = inorderSuccessor(root -> right);
            root -> val = inorderSucc -> val;
            root -> right = deleteNode(root -> right, inorderSucc -> val);
        }
        return root;
    }
};