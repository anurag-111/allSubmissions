// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    
    private int index;

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        
        if (root == null) {
            return "X";
        }
        
        String left = serialize(root.left);
        String right = serialize(root.right);
        
        return root.val + "," + left + "," + right;
        
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        
        String[] serialTree = data.split(",");
        return deserializeTree(serialTree);
    }
    
    private TreeNode deserializeTree(String[] serialTree) {
        
        if (index == serialTree.length || serialTree[index].equals("X")) {
            index++;
            return null;
        }
        
        TreeNode root = new TreeNode(Integer.parseInt(serialTree[index]));
        index++;
        root.left = deserializeTree(serialTree);
        root.right = deserializeTree(serialTree);
        return root;
    }
}
// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));