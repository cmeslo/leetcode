class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = [0] * len(T)
        stack = []
        for i in range(len(T)):
            while stack and T[stack[-1]] < T[i]:
                top = stack[-1]
                res[top] = i - stack.pop()
            stack.append(i)
        return res
    
