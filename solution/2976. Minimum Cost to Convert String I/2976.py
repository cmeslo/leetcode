class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        dist = [[float('inf')] * 26 for _ in range(26)]
        
        for i in range(len(cost)):
            a, b = ord(original[i]) - ord('a'), ord(changed[i]) - ord('a')
            dist[a][b] = min(dist[a][b], cost[i])
        
        for i in range(26):
            dist[i][i] = 0
        
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if dist[i][k] == float('inf') or dist[k][j] == float('inf'):
                        continue
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        
        res = 0
        for i in range(len(target)):
            a, b = ord(source[i]) - ord('a'), ord(target[i]) - ord('a')
            if dist[a][b] == float('inf'):
                return -1
            res += dist[a][b]
        return res
    
