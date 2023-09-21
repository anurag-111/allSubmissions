// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    void count_node(TreeNode* root, int cur_max, int& count) {
        if (!root) {
            return;
        }
        if (root -> val >= cur_max) {
            count++;
            cur_max = root -> val;
        }
        count_node(root -> left, cur_max, count);
        count_node(root -> right, cur_max, count);
    }
public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        int cur_max = root -> val;
        int count = 0;
        count_node(root, cur_max, count);
        return count;
    }
};