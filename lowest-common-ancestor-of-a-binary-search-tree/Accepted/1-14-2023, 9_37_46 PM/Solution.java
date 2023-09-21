// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }

        if (root.val == p.val || root.val == q.val) {
            return root;
        }

        TreeNode lca1 = lowestCommonAncestor (root.left, p, q);
        TreeNode lca2 = lowestCommonAncestor (root.right, p, q);

        if (lca1 != null && lca2 != null) {
            return root;
        }
        if (lca1 != null) {
            return lca1;
        } else {
            return lca2;
        }
    }
}

// 1. If it is same as p or q.
// 2. If one of it's subtrees contain p and other contains q.
// 3. If one of it's subtrees contain both p and q.
// 4. If none of it's subtrees contain p and q.















