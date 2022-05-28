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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        
        if (root.val == key) {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
            else {
                TreeNode pre = null;
                TreeNode new_node = root.right;
                while (new_node.left != null) {
                    pre = new_node;
                    new_node = new_node.left;
                }
                if (pre == null) {
                    new_node.left = root.left;
                    return new_node;
                }
                pre.left = new_node.right;
                new_node.left = root.left;
                new_node.right = root.right;
                return new_node;
            }
        }
        
        if (key < root.val)
            root.left = deleteNode(root.left, key);
        else if (root.val < key)
            root.right = deleteNode(root.right, key);
        return root;
    }
}
