// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr) {
            return true;
        }

        if ((minNode != nullptr && root->val <= minNode->val) || (maxNode != nullptr && root->val >= maxNode->val)) {
            return false;
        }

        bool leftValid = isValid(root->left, minNode, root);
        bool rightValid = isValid(root->right, root, maxNode);
        
        return leftValid && rightValid;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};
