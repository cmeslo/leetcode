# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        res, mx, level = 1, root.val, 1
        q = collections.deque()
        q.append(root)
        while q:
            sum = 0
            for _ in range(len(q)):
                node = q.popleft()
                sum += node.val
                if (node.left): q.append(node.left)
                if (node.right): q.append(node.right)
            if sum > mx:
                mx, res = sum, level
            level += 1
        return res
