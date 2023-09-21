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

// For printing the values too
class Solution {
public:
    vector<pair<int, int>> maxDiffNodes; // To store nodes with maximum difference.
    int maxAncestorDiff(TreeNode* root) {
        int maxValue = INT_MIN;
        dfs(root, root->val, root->val, maxValue);

        for(auto pair : maxDiffNodes) {
            cout << pair.first << " " << pair.second << endl;
        }

        return maxValue;
    }

    void dfs(TreeNode* root, int minimum, int maximum, int& maxValue) {
        if (root == nullptr) {
            return;
        }

        int currentMax;
        
        if (abs(root->val - minimum) > abs(root->val - maximum)) {
            currentMax = abs(root->val - minimum);
             if (currentMax > maxValue) {
                maxValue = currentMax;
                maxDiffNodes.clear(); 
                maxDiffNodes.push_back({root->val, minimum});
            }
            
        } else {
            currentMax =  abs(root->val - maximum);
            if (currentMax > maxValue) {
                maxValue = currentMax;
                maxDiffNodes.clear(); 
                maxDiffNodes.push_back({root->val, maximum});
            }
        }

        dfs(root->left, min(root->val, minimum), max(root->val, maximum), maxValue);
        dfs(root->right, min(root->val, minimum), max(root->val, maximum), maxValue);
    }
};
