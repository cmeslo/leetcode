# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        def dfs(node):
            if not node: return "null"
            struct = "%s,%s,%s" % (str(node.val), dfs(node.left), dfs(node.right))
            nodes[struct].append(node)
            return struct
        nodes = collections.defaultdict(list)
        dfs(root)
        return [nodes[struct][0] for struct in nodes if len(nodes[struct]) > 1]
