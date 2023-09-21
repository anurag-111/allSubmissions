// https://leetcode.com/problems/binary-tree-right-side-view

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
private :
    void view (TreeNode* root, vector<int>& result, int level) {
        if(!root) {
            return;
        }
        if(result.size() == level) {
            result.push_back(root -> val);
        }
        view (root -> right, result, level + 1);
        view (root -> left, result, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        view (root, result, 0);
        return result;
    }
};

// TC : O(n)
// SC : O(h)
// For every level, the first node (on the right side) will be our right side view.
// If the level of the tree == vector's size, push it into the vector.
// If we reach a null node, just return (base case).