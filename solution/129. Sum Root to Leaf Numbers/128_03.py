# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        res = 0
        st = []
        st.append(root)
        
        while st:
            node = st.pop()
            if not node.left and not node.right:
                res += node.val
            if node.right:
                node.right.val += node.val * 10
                st.append(node.right)
            if node.left:
                node.left.val += node.val * 10
                st.append(node.left)
        return res
    
        
