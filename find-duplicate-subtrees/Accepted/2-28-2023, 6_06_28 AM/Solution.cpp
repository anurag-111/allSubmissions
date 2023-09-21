// https://leetcode.com/problems/find-duplicate-subtrees

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
        vector<TreeNode*> ans;
        unordered_map<string, int> mymap;
       
        string helper(TreeNode* root) {
            if(root == NULL) {
                return "";
            }
            
            string left = helper(root->left);
            string right = helper(root->right);

            // Create strings for the subpaths
            string sub_path = "(" + left + to_string(root->val) + right + ")"; 
            
            // New string found, insert it and increase the frequency.
            if(mymap[sub_path] != -1) {
                mymap[sub_path]++;
            } 
        
            // Same string found then a duplicate subtree has been found.
            if(mymap[sub_path] > 1) {
                ans.push_back(root);
                mymap[sub_path] = -1;       // Decrement the frequency
            }
            return sub_path; 
        }

    public:
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            helper(root);
            return ans;
        }
};

