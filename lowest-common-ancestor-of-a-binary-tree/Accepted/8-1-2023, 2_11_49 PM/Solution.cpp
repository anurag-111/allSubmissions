// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

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
        // Base case: If the root is NULL or one of the nodes is the root, return the root itself (or NULL).
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Recursively find the LCA in the left and right subtrees.
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // Result:
        // If one of the subtrees returns NULL, it means that both nodes are in the other subtree,
        // so we return the non-NULL result (the LCA found in the other subtree).
        if (leftLCA == nullptr) {
            return rightLCA;
        } else if (rightLCA == nullptr) {
            return leftLCA;
        }
        // If both left and right subtrees return non-NULL results, it means that each node is present
        // in one of the subtrees, so the current root node is the LCA.
        return root;
    }
};

/*
Time Complexity: The time complexity of the lowestCommonAncestor function is O(n), 
where "n" is the number of nodes in the binary tree. In the worst case, 
the algorithm may have to visit all nodes in the tree to find the lowest common ancestor.

Space Complexity: The space complexity of the lowestCommonAncestor function is O(n),
in the worst-case scenario, the binary tree can be highly unbalanced, with each node having only one child, 
leading to a linear chain of nodes from the root to a leaf. In this case, the height of the binary tree 
is equal to the number of nodes, which is "n." Therefore, the space complexity becomes O(n) because 
the recursion can go as deep as the number of nodes in the tree.
*/