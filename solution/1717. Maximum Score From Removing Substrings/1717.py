class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        a, b = 'a', 'b'
        if x < y:
            a, b = b, a
            x, y = y, x
        
        def remove(s, a, b):
            st = []
            for c in s:
                if st and st[-1] == a and c == b:
                    st.pop()
                else:
                    st.append(c)
            return ''.join(st)
        
        s1 = remove(s, a, b)
        s2 = remove(s1, b, a)
        return (len(s) - len(s1)) // 2 * x + ((len(s1) - len(s2)) // 2 * y)
        
