// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        int maxLevel = -1;                      // Stores the level with the maximum sum
        int currentLevel = 0;                   // Tracks the current level
        int maxSum = INT_MIN;                   // Stores the maximum sum found
        queue<TreeNode*> nodeQueue;             // Queue to perform level order traversal

        nodeQueue.push(root);                   // Start with the root node

        while (!nodeQueue.empty()) {
            currentLevel++;                      // Move to the next level
            int levelSize = nodeQueue.size();    // Get the number of nodes at the current level
            int currentLevelSum = 0;             // Stores the sum of node values at the current level

            // Iterate through all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                currentLevelSum += currentNode->val;     // Accumulate the node values

                // Add the children of the current node to the queue
                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                    
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }

            // Check if the sum at the current level is greater than the maximum sum.
            // If so, update the maxSum and maxLevel accordingly
            if (currentLevelSum > maxSum) {
                maxLevel = currentLevel;
                maxSum = currentLevelSum;
            }
        }

        return maxLevel;                         // Return the level with the maximum sum
    }
};
