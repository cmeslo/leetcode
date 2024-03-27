class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        
        def first_occurence(x):
            l, r = 0, n
            while l < r:
                m = (l + r) // 2
                if arr[m] < x:
                    l = m + 1
                else:
                    r = m
            return l
        
        def last_occurence(x):
            l, r = 0, n
            while l < r:
                m = (l + r) // 2
                if arr[m] <= x:
                    l = m + 1
                else:
                    r = m
            return l - 1
        
        for x in [arr[n//4], arr[n//2], arr[n*3//4]]:
            l, r = first_occurence(x), last_occurence(x)
            if r - l + 1 > n/4:
                return x
        return -1
