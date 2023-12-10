class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        adj = [[] for _ in range(n)]
        for i in range(len(edges)):
            a, b = edges[i]
            p = succProb[i]
            adj[a].append((b, p))
            adj[b].append((a, p))
        
        q = [(-1.0, start)]
        dist = [0.0] * n
        while q:
            p, node = heapq.heappop(q)
            p = -p
            if node == end:
                return p
            if dist[node] >= p:
                continue
            dist[node] = p
            for next, p2 in adj[node]:
                p_next = p * p2
                if p_next > dist[next]:
                    heapq.heappush(q, (-p_next, next))
        return 0.0
