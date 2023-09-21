// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxpathsum_util(TreeNode* root, int &result) {
        if (!root) {
            return 0;
        }
        
        int left = maxpathsum_util (root->left, result);
        int right = maxpathsum_util (root->right, result);
        
        int max_straight = max(max(left,right) + root -> val, root -> val);
        int max_case_val = max(max_straight, left + right + root -> val);
        result = max(max_case_val, result);
        
        return max_straight;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxpathsum_util(root, result);
        return result;
    }
};

/*
  CASE 1 : current node is in the path of max sum
  
       1
      / \
     2   3
    / \
   2   1  
  
  ms = max (max(left, right) + root->val, root->val)
  
  CASE 2 : current node is the root of max sum path
  
       1
      / \
     2   2
    / \
   8   8
  /
-2

 m21 = max (ins, left + right + root->val)
 
 CASE 3 : current node is not in path of the sum
 
       1
      / \
     2   2
    / 
   8   
  / \
100 100
 
 result = max(m21, result)

*/