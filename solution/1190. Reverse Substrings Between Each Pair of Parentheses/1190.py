class Solution:
    def reverseParentheses(self, s: str) -> str:
        L = []
        s = list(s)  # 將字符串轉換為列表，因為 Python 字符串是不可變的

        for i in range(len(s)):
            if s[i] == '(':
                L.append(i)
            elif s[i] == ')':
                s[L[-1]+1:i] = s[L[-1]+1:i][::-1]
                L.pop()

        return ''.join(c for c in s if c not in '()')
