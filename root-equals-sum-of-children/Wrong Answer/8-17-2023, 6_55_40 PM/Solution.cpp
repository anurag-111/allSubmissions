// https://leetcode.com/problems/root-equals-sum-of-children

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
    int sum(TreeNode* node) {
        return node -> val;
    }
public:
    bool checkTree(TreeNode* root) {
        int rootValue = root -> val;
        
        int leftValue = sum(root -> left);
        int rightValue = sum(root -> right);
        
        int childrenValue = leftValue + rightValue;
        
        return rootValue = childrenValue ? true : false;
    }
};