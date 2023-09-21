// https://leetcode.com/problems/maximum-depth-of-binary-tree

// Definition for a binary tree node 
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
private:
    // Helper function to calculate the depth of the binary tree
    int calculateDepth(TreeNode* root) {
        // Base case: If the current node is NULL, return 0 (no depth)
        if (root == NULL) {
            return 0;
        }
        
        // Recursively calculate the depths of the left and right subtrees
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        
        // Return the depth of the current node by adding 1 to the maximum depth of its subtrees
        return 1 + max(leftDepth, rightDepth);
    }
    
public:
    // Function to return the maximum depth of the binary tree
    int maxDepth(TreeNode* root) {
        // Call the helper function to calculate the depth
        return calculateDepth(root);
    }
};

// TC : O(N)
// SC : O(N)