# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        children = set()
        m = {}
        
        for root_val, child_val, is_left in descriptions:
            root = m.setdefault(root_val, TreeNode(root_val))
            child = m.setdefault(child_val, TreeNode(child_val))
            if is_left:
                root.left = child
            else:
                root.right = child
            children.add(child_val)
        
        root = (set(m) - set(children)).pop()
        return m[root]
    
