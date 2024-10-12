class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        dirs = [0, 1, 0, -1, 0]
        
        def dfs(i, j, k):
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            
            old = board[i][j]
            board[i][j] = '#'
            for d in range(4):
                y = i + dirs[d]
                x = j + dirs[d + 1]
                if dfs(y, x, k + 1):
                    return True
            board[i][j] = old
            return False
        
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
    
