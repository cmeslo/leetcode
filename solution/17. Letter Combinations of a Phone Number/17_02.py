class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        
        m = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        res = []
        res.append("")

        for d in digits:
            tmp = []
            for prefix in res:
                for c in m[d]:
                    tmp.append(prefix + c)
            res = tmp
        return res
