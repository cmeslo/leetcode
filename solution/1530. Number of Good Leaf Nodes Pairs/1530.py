# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        res = 0
        
        def dfs(node):
            nonlocal res
            count = [0] * (distance + 1)
            if not node:
                return count
            
            l = dfs(node.left)
            r = dfs(node.right)
            
            for i in range(distance):
                for j in range(distance):
                    if i + j + 2 > distance:
                        break
                    res += l[i] * r[j]
            
            for i in range(distance):
                count[i + 1] = l[i] + r[i]
            
            if not node.left and not node.right:
                count[0] = 1
            
            return count
        
        dfs(root)
        return res
