// https://leetcode.com/problems/minimum-absolute-difference-in-bst

class Solution {
private:
    vector<int> nodes; // Stores the values of the tree nodes during inorder traversal

    // Performs inorder traversal of the tree and populates the 'nodes' vector
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorderTraversal(root->left); // Traverse left subtree
        nodes.push_back(root->val); // Store the value of the current node
        inorderTraversal(root->right); // Traverse right subtree
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root); // Perform inorder traversal to populate 'nodes' vector

        int minDifference = INT_MAX;
        for (int i = 1; i < nodes.size(); i++) {
            // Calculate the difference between adjacent nodes and update the minimum difference
            minDifference = min(minDifference, nodes[i] - nodes[i - 1]);
        }

        return minDifference;
    }
};
