class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        res = [[0] * n for i in range(m)]
        for i in range(m):
            for j in range(n):
                s, cnt = 0, 0
                for y in range(max(0, i-1), min(m, i+2)):
                    for x in range(max(0, j-1), min(n, j+2)):
                        s += img[y][x]
                        cnt += 1
                res[i][j] = s // cnt;
        return res
    
