class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        res = pre = 0
        for row in bank:
            cnt = row.count('1')
            res += pre * cnt
            if cnt > 0:
                pre = cnt
        return res
    
