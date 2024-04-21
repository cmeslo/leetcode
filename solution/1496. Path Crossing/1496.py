class Solution:
    def isPathCrossing(self, path: str) -> bool:
        x = y = 0
        seen = {(x, y)}
        for d in path:
            if d == 'N':
                y += 1
            elif d == 'S':
                y -= 1
            elif d == 'E':
                x += 1
            elif d == 'W':
                x -= 1
            if (x, y) in seen:
                return True
            seen.add((x, y))
        return False
    
