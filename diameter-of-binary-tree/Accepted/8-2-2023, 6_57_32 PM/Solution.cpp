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
private:
    int diameter; // Variable to store the diameter of the binary tree.

    // Helper function to calculate the maximum depth of each subtree rooted at the given node.
    int calculateMaxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum depth of the left and right subtrees.
        int leftDepth = calculateMaxDepth(root->left);
        int rightDepth = calculateMaxDepth(root->right);

        // Update the diameter if the current path is longer.
        diameter = max(diameter, (leftDepth + rightDepth));

        // Return the maximum depth of the subtree rooted at the current node.
        return 1 + max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0; // Initialize the diameter to 0 before the calculation.
        calculateMaxDepth(root); // Start the recursive traversal to calculate the max depth.
        return diameter; // Return the final diameter of the binary tree.
    }
};
