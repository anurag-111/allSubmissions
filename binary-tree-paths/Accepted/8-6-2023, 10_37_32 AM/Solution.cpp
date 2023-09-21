// https://leetcode.com/problems/binary-tree-paths

class Solution {
private:
    // Recursive function to find all paths from the root to leaf nodes
    vector<string> paths(TreeNode* root, vector<string>& result, string str) {
        // If the current node is a leaf node, add the current path to the result
        if (root->left == NULL && root->right == NULL) {
            result.push_back(str);
        }

        // If the left child exists, recursively explore the left subtree
        if (root->left) {
            paths(root->left, result, str + "->" + to_string(root->left->val));
        }

        // If the right child exists, recursively explore the right subtree
        if (root->right) {
            paths(root->right, result, str + "->" + to_string(root->right->val));
        }

        return result;
    }

public:
    // Function to find all root-to-leaf paths in a binary tree
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        // If the tree is empty, return an empty result
        if (root == NULL) {
            return result;
        }

        // Start the path with the root value and explore all possible paths
        return paths(root, result, to_string(root->val));
    }
};
