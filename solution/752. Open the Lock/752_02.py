class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        init = "0000"
        if init in dead:
            return -1
        if init == target:
            return 0
        
        q1, q2 = {init}, {target}
        ans = 0
        while q1 and q2:
            if len(q1) > len(q2):
                q1, q2 = q2, q1
                
            q = set()
            for s in q1:
                for i in range(4):
                    for j in [-1, 1]:
                        code = s[:i] + str((int(s[i]) + j + 10) % 10) + s[i+1:]
                        if code in q2:
                            return ans + 1
                        if code in dead:
                            continue
                        dead.add(code)
                        q.add(code)
                        
            q1 = q
            ans += 1
        return -1
