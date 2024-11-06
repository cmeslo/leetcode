# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        def dfs(node, d, is_left):
            if d == 1:
                new_node = TreeNode(val)
                if is_left:
                    new_node.left = node
                else:
                    new_node.right = node
                return new_node
            
            if not node:
                return node
            
            node.left = dfs(node.left, d - 1, True)
            node.right = dfs(node.right, d - 1, False)
            return node
        
        return dfs(root, depth, True)
    
