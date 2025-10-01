class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        obstacles = set(map(tuple, obstacles))
        res = y = x = d = 0
        for c in commands:
            if c == -1:
                d = (d + 1) % 4
            elif c == -2:
                d = (d - 1) % 4
            else:
                dx, dy = dirs[d]
                while c and (x + dx, y + dy) not in obstacles:
                    x += dx
                    y += dy
                    c -= 1
            res = max(res, x * x + y * y)
        return res
    
