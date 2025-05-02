class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = defaultdict(list)
        res = [[] for _ in range(n)]
        for a, b in edges:
            adj[a].append(b)
        
        def dfs(node, root):
            for nxt in adj[node]:
                if res[nxt] and res[nxt][-1] == root: continue
                res[nxt].append(root)
                dfs(nxt, root)
        
        for i in range(n):
            dfs(i, i)
        return res
