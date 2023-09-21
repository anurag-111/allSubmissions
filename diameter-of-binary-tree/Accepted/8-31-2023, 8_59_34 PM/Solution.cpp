// https://leetcode.com/problems/diameter-of-binary-tree

class Solution {
private: 
    int calculateDiameter(TreeNode *root, int &diameter) {
        // Base Case: If the node is NULL, return 0.
        if (root == NULL) {
            return 0;
        }

        // Recursive calls to calculate heights of left and right subtrees.
        int leftHeight = calculateDiameter(root->left, diameter);
        int rightHeight = calculateDiameter(root->right, diameter);

        // The height of the current node
        int height = 1 + max(leftHeight, rightHeight);

        // The current diameter passing through the current node
        int currentDiameter = leftHeight + rightHeight;

        // Update the overall maximum diameter found so far
        diameter = max(diameter, currentDiameter);

        // Return the height of the current node
        return height;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }
};
