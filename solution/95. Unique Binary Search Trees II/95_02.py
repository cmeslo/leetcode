# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def trees(start, end):
            return [TreeNode(i, l, r)
                    for i in range(start, end + 1)
                    for l in trees(start, i - 1)
                    for r in trees(i + 1, end)] or [None]
        
        return trees(1, n)
