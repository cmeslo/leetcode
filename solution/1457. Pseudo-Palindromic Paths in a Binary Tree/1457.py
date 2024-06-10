# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def dfs(node, x):
            if not node : return 0
            x ^= (1 << node.val)
            if not (node.left or node.right):
                return 1 if x == 0 or (x & (x - 1)) == 0 else 0
            return dfs(node.left, x) + dfs(node.right, x)
            
        return dfs(root, 0)
    
