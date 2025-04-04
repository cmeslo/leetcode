class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        n = len(position)
        position.sort()
        
        def check_ok(d):
            cnt = 1
            pre = position[0]
            
            for i in range(1, n):
                if position[i] - pre >= d:
                    cnt += 1
                    if cnt >= m: return True
                    pre = position[i]
            return False
        
        l, r = 0, position[-1] - position[0]
        while l < r:
            mid = r - (r - l) // 2
            if check_ok(mid):
                l = mid
            else:
                r = mid - 1
        return l
    
