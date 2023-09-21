// https://leetcode.com/problems/diameter-of-binary-tree

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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculate(root, diameter);
        return diameter;
    }
private:
    int calculate(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        
        int left_height = calculate(root->left, diameter);
        int right_height = calculate(root->right, diameter);
        
        diameter = max(diameter, (left_height + right_height));
        return max(left_height, right_height) + 1;
    }
};

//TC : O(n)
//SC : O(n)