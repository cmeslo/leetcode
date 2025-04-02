class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def check_ok(t):
            res = cnt = 0
            for x in bloomDay:
                if x <= t:
                    cnt += 1
                    if cnt >= k:
                        res += 1
                        cnt = 0
                        if res >= m:
                            return True
                else:
                    cnt = 0
            return False
        
        left, right = 0, 10**9 + 1
        while left < right:
            mid = (left + right) // 2
            if check_ok(mid):
                right = mid
            else:
                left = mid + 1
        return -1 if left == 10**9 + 1 else left
        
