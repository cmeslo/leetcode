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
    
    private int id = 0;
    
    private TreeNode constructBST(int[] preorder, int bound) {
        if (id == preorder.length || preorder[id] > bound) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[id++]);
        root.left = constructBST(preorder, root.val);
        root.right = constructBST(preorder, bound);
        return root;
    }
    
    public TreeNode bstFromPreorder(int[] preorder) {
        return constructBST(preorder, Integer.MAX_VALUE);
    }
}
