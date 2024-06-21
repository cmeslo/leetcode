class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        q = deque()
        for i in range(1, 10):
            q.append(i)
        
        while q:
            x = q.popleft()
            if x > high:
                break
            if low <= x:
                res.append(x)
            last = x % 10
            if last < 9:
                q.append(x * 10 + last + 1)
        return res
    
