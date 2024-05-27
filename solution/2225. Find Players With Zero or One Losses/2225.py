class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        lost = {}
        for m in matches:
            lost[m[0]] = lost.get(m[0], 0)
            lost[m[1]] = lost.get(m[1], 0) + 1
        
        res = [[], []]
        for player, cnt in lost.items():
            if cnt < 2:
                res[cnt].append(player)
            
        res[0].sort()
        res[1].sort()
        return res
    
        
