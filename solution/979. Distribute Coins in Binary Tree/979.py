# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = 0
    
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def balance(node):
            if not node: return 0
            l = balance(node.left)
            r = balance(node.right)
            self.res += abs(l) + abs(r)
            return l + r + node.val - 1
        
        balance(root)
        return self.res
    
