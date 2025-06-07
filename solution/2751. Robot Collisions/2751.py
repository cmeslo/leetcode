class Solution:
    def survivedRobotsHealths(self, positions: List[int], H: List[int], directions: str) -> List[int]:
        n = len(positions)
        robots = [[positions[i], i] for i in range(n)]
        robots.sort()
        stack = []
        
        for _, i in robots:
            if directions[i] == 'R':
                stack.append(i)
                continue
            while stack and H[i] > 0:
                if H[stack[-1]] < H[i]:
                    H[stack.pop()] = 0
                    H[i] -= 1
                elif H[stack[-1]] > H[i]:
                    H[stack[-1]] -= 1
                    H[i] = 0
                else:
                    H[stack.pop()] = 0
                    H[i] = 0
        
        return [h for h in H if h > 0]
