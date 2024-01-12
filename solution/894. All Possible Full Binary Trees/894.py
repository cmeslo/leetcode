# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        if n == 1:
            return [ TreeNode() ]

        res = []
        for i in range(1, n - 1, 2):
            l_nodes = self.allPossibleFBT(i)
            r_nodes = self.allPossibleFBT(n - 1 - i)
            for l in l_nodes:
                for r in r_nodes:
                    node = TreeNode()
                    node.left = l
                    node.right = r
                    res.append(node)
        return res
