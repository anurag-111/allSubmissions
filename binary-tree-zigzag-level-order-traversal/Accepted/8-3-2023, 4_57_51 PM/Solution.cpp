// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> result;

    // Helper function to perform zigzag level order traversal
    void zigzagTraversal(TreeNode* root) {
        // Check if the root is null
        if (root == NULL) {
            return;
        }

        // Create a queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Variable to track the direction of traversal (left to right or right to left)
        bool leftToRight = true;

        while (!q.empty()) {
            // Get the current level size
            int levelSize = q.size();

            // Vector to store the values of the current level
            vector<int> currentLevel;

            // Process nodes in the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Add node values in the current level based on the direction of traversal
                if (leftToRight) {
                    currentLevel.push_back(node->val); // Add node values from left to right
                } else {
                    currentLevel.insert(currentLevel.begin(), node->val); // Add node values from right to left
                }

                // Add the children of the current node to the queue for the next level traversal
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            // Toggle the direction for the next level traversal
            leftToRight = !leftToRight;

            // Store the values of the current level in the result
            result.push_back(currentLevel);
        }
    }

public:
    // Function to perform zigzag level order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Call the helper function for zigzag traversal
        zigzagTraversal(root);

        // Return the final result
        return result;
    }
};

/* 

currentLevel.insert(currentLevel.begin(), node->val); inserts the value node->val 
at the beginning of the currentLevel vector. This effectively reverses the order of 
elements in the vector, pushing new nodes to the front of the vector as they are 
visited during the zigzag traversal.

*/
