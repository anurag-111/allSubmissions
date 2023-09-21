// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int maxWidth = INT_MIN;

        while(!q.empty()){
            int start = q.front().second;
            int end = q.back().second;
            
            maxWidth = max(maxWidth, end - start + 1);
            
            int count = q.size();
            
            while(count--){
                int idx = q.front().second - end;
                
                TreeNode* node = q.front().first;
                q.pop();
                
                if(node->left) {
                    q.push({node->left, 2 * idx + 1});
                }
                    
                if(node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
        }
        
        return maxWidth;
    }
};