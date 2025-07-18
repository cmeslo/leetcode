class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        
        @cache
        def dfs(start):
            if start >= n:
                return 0
            res = float('inf')
            w = h = 0
            for i in range(start, n):
                if w + books[i][0] > shelfWidth:
                    break
                w += books[i][0]
                h = max(h, books[i][1])
                res = min(res, h + dfs(i + 1))
            return res
        
        return dfs(0)
    
