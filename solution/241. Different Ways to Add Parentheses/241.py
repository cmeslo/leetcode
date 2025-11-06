class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        
        def dfs(start, end):
            res = []
            for i in range(start, end + 1):
                if expression[i].isdigit():
                    continue
                
                L = dfs(start, i - 1)
                R = dfs(i + 1, end)
                for l in L:
                    for r in R:
                        res.append(self.calc(l, r, expression[i]))
            if not res:
                res.append(int(expression[start:end+1]))
            return res
        
        return dfs(0, len(expression) - 1)
        
    
    def calc(self, a, b, op):
        if op == '+':
            return a + b
        if op == '-':
            return a - b
        if op == '*':
            return a * b
        return 0
