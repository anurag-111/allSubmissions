// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

// Recursive Approach 
class Solution {
private:
    TreeNode* calculateLCA(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == NULL) {
            return NULL;
        }

        if(root -> val > p -> val && root -> val > q -> val) {
            return calculateLCA(root -> left, p, q);
        } 
        
        if(root -> val < p -> val && root -> val < q -> val) {
            return calculateLCA(root -> right, p, q);
        }

        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return calculateLCA(root, p, q);
    }
};

// TC : O(N)
// SC : O(H)