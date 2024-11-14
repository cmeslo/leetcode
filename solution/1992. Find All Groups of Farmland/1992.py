class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        
        res = []
        for i in range(m):
            for j in range(n):
                if land[i][j] != 1:
                    continue
                y, x = i, j
                while y < m and land[y][j] == 1:
                    y += 1
                while x < n and land[i][x] == 1:
                    x += 1
                y -= 1
                x -= 1
                res.append([i, j, y, x])
                
                for a in range(i, y + 1):
                    for b in range(j, x + 1):
                        land[a][b] = 2
        return res
                    
        
