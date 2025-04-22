# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        A = []
        
        def dfs(node):
            if not node: return None
            dfs(node.left)
            A.append(node)
            dfs(node.right)
        
        dfs(root)
        
        def build(A, l, r):
            if l > r: return None
            
            mid = (l + r) // 2
            A[mid].left = build(A, l, mid - 1)
            A[mid].right = build(A, mid + 1, r)
            return A[mid]
        
        return build(A, 0, len(A) - 1)
    
                
