// https://leetcode.com/problems/binary-tree-level-order-traversal

// Definition for a binary tree node (assuming it's already defined somewhere else)
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    // Function to perform level-order traversal of a binary tree
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Initialize a 2D vector to store the result
        vector<vector<int>> result;
        
        // Base case: If the tree is empty, return the empty result vector
        if (!root) {
            return result;
        }

        // Create a queue to hold the nodes of the current level
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            // Get the number of nodes in the current level
            int size = q.size();
            
            // Create a vector to store the nodes' values in the current level
            vector<int> currentLevel;
            
            // Process all the nodes in the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();
                
                // Add the node's value to the current level vector
                currentLevel.push_back(node->val);
                
                // Enqueue the left and right children of the current node if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            // Add the current level vector to the result
            result.push_back(currentLevel);
        }
        
        // Return the final result containing the level-order traversal
        return result;
    }
};
