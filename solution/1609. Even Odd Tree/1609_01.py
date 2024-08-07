# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = [root]
        inc = True
        while q:
            pre = -1 if inc else 10**6 + 1
            for _ in range(len(q)):
                node = q.pop(0)
                if inc:
                    if pre >= node.val or node.val % 2 == 0:
                        return False
                else:
                    if pre <= node.val or node.val % 2 == 1:
                        return False
                pre = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            inc = not inc
        return True
    
