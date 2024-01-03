class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(n)]
        colors = [0 for _ in range(n)] # 0: unknow, 1: visiting, 2: visited

        for a, b in prerequisites:
            adj[a].append(b)
        
        def dfs(node):
            if colors[node] == 1:
                return False
            if colors[node] == 2:
                return True
            colors[node] = 1
            for next in adj[node]:
                if not dfs(next):
                    return False
            colors[node] = 2
            return True
        
        for i in range(n):
            if not dfs(i):
                return False
        return True
