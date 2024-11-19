class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n <= 2:
            return [i for i in range(n)]
        
        adj = [[] for _ in range(n)]
        in_degree = [0] * n
        
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
            in_degree[a] += 1
            in_degree[b] += 1
        
        q = deque()
        for i in range(n):
            if in_degree[i] == 1:
                q.append(i)
        
        cnt = n
        while cnt > 2:
            cnt -= len(q)
            for _ in range(len(q)):
                node = q.popleft()
                for neighbor in adj[node]:
                    in_degree[neighbor] -= 1
                    if in_degree[neighbor] == 1:
                        q.append(neighbor)
        
        return list(q)
    
