class Solution:
    def trap(self, H: List[int]) -> int:
        res = 0
        st = []
        for i, h, in enumerate(H):
            while st and H[st[-1]] < H[i]:
                base = H[st.pop()]
                if st:
                    h = min(H[st[-1]], H[i]) - base
                    w = i - st[-1] - 1
                    res += h * w
            st.append(i)
        return res
