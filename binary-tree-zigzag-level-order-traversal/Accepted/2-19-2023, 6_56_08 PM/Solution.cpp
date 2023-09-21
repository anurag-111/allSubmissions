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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            int node_count = q.size();
            int n = node_count;
            vector<int> level;

            while(n--) {
                TreeNode *curr = q.front();

                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }

                q.pop();
                level.push_back(curr->val);
            }

            if(flag) {
                reverse(level.begin(), level.end());
            }
            result.push_back(level);
            flag = !flag;
        } 
        return result;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)















