// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    // Function to find the maximum ancestor difference in a binary tree.
    int maxAncestorDiff(TreeNode* root) {
        int maxValue = INT_MIN;
        // Call the DFS function to traverse the tree and find the maximum difference.
        dfs(root, root->val, root->val, maxValue);
        return maxValue; // Return the maximum difference found in the tree.
    }

    // Depth-First Search (DFS) function to traverse the binary tree and find the maximum difference.
    void dfs(TreeNode* root, int minimum, int maximum, int& maxValue) {
        if (root == nullptr) {
            return; // Base case: If the current node is null, return.
        }

        // Calculate the absolute difference between the current node's value
        // and the minimum and maximum values seen in the path from the root.
        int currentMax = max(abs(root->val - minimum), abs(root->val - maximum));

        // Update the global maximum difference seen so far.
        maxValue = max(currentMax, maxValue);

        // Recur on the left and right subtrees, updating the minimum and maximum values
        // seen so far in the path from the root to the current node.
        dfs(root->left, min(root->val, minimum), max(root->val, maximum), maxValue);
        dfs(root->right, min(root->val, minimum), max(root->val, maximum), maxValue);
    }
};

// Time complexity : O(n)
// Space complexity : O(n)
