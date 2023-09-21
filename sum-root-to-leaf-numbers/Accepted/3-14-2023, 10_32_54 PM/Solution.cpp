// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int sum =0;
    
    void findSum(TreeNode *root, int number){
        
        if(!root) {
            return;
        }            
        
        number = number * 10 + root->val;
        
        if(!root->left && !root->right){
            sum += number;
        }
            
        findSum(root->left, number);
        
        findSum(root->right, number);
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(!root) {
            return 0;
        }            
        
        findSum(root,0);
        
        return sum;
    }
};