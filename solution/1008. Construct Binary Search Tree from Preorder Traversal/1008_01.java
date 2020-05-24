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
    
    private TreeNode construct(int[] preorder, int start, int end) {
        
        int len = preorder.length;
        if (start == -1) {
            // System.out.println("build [null]");
            return null;
        }
        // System.out.println("build [start: " + start + ", end: " + end + "]");
        
        int val = preorder[start], left = -1, right = -1;
        for (int i = start+1; i <= end; i++) {
            if (preorder[i] < val) {
                left = i; break;
            }
        }
        for (int i  = start+1; i <= end; i++) {
            if (preorder[i] > val) {
                right = i; break;
            }
        }
        
        TreeNode root = new TreeNode(val);
        if (right != -1) {
            root.right = construct(preorder, right, end);
            root.left = construct(preorder, left, right-1);
        } else {
            root.left = construct(preorder, left, end);
        }
        return root;
    }
    
    public TreeNode bstFromPreorder(int[] preorder) {
        if (preorder.length == 0)
            return null;
        return construct(preorder, 0, preorder.length-1);
    }
}
