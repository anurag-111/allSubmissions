// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            int currentValue = root->val;
            
            if (currentValue > p->val && currentValue > q->val) {
                // Both p and q are in the left subtree.
                root = root->left;
            } else if (currentValue < p->val && currentValue < q->val) {
                // Both p and q are in the right subtree.
                root = root->right;
            } else {
                // Found the lowest common ancestor.
                break;
            }
        }

        return root;
    }
};

// Time Complexity: The time complexity of the lowestCommonAncestor function is O(h), 
// where "h" is the height of the binary search tree. In the worst case scenario, 
// the algorithm traverses from the root to the lowest common ancestor, 
// which takes time proportional to the height of the tree.

// Space Complexity: The space complexity of the lowestCommonAncestor function is O(1). 
// The algorithm uses a constant amount of extra space for the currentValue variable and 
// the loop variable root. It does not utilize any additional data structures that grow with 
// the input size or the height of the tree. Hence, the space complexity is constant.