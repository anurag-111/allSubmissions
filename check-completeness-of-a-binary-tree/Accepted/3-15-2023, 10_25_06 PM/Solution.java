// https://leetcode.com/problems/check-completeness-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        
        if(root == null) {
            return true;
        }
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        
        q.add(root);
        
        while(!q.isEmpty()){
            
            TreeNode cur = q.remove();
            
            if(cur == null) {
                break;
            } 
            
            q.add(cur.left);
            q.add(cur.right);
        }
        
        while(!q.isEmpty() && q.peek() == null) {
            q.remove();
        } 

        return q.isEmpty();
    }
}