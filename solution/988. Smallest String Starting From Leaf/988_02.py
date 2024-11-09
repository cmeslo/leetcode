# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode], s="") -> str:
        if not root:
            return chr(255)
        
        s = chr(root.val + ord('a')) + s
        
        if root.left == root.right:
            return s
        
        return min(self.smallestFromLeaf(root.left, s),
                   self.smallestFromLeaf(root.right, s))
    
