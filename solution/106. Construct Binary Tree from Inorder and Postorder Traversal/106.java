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
    private int postIndex;
    private int[] inorder, postorder;
    private HashMap<Integer, Integer> m;
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.inorder = inorder;
        this.postorder = postorder;
        m = new HashMap<Integer, Integer>();
        for (int i = 0; i < inorder.length; ++i)
            m.put(inorder[i], i);
        
        postIndex = postorder.length - 1;
        return buildTree(0, inorder.length - 1);
    }
    
    private TreeNode buildTree(int inStart, int inEnd) {
        if (inStart > inEnd) return null;
        int rootVal = postorder[postIndex--];
        TreeNode root = new TreeNode(rootVal);
        root.right = buildTree(m.get(rootVal) + 1, inEnd);
        root.left = buildTree(inStart, m.get(rootVal) - 1);
        return root;
    }
}
