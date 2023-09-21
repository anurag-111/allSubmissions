// https://leetcode.com/problems/subtree-of-another-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool areIdentical(TreeNode* root, TreeNode* subRoot) {
        //base cases
        if (root == NULL || subRoot == NULL) {
            return (root == subRoot);
        }

        //check if the data of both roots is same and data of left and right subtrees are also same
        return ((root->val == subRoot->val) && 
                areIdentical(root->left, subRoot->left) && 
                areIdentical(root->right, subRoot->right));

    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //base cases
        if (root == NULL) {
            return false;
        }
        if (subRoot == NULL) {
            return true;
        }
        
        //check the tree with root as current node
        if (areIdentical(root, subRoot)) {
            return true;
        }
        
        //if the tree with root as current node does not match then try left and right subtrees one by one
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};