class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        A = []
        for x in nums:
            if not A or A[-1] < x:
                A.append(x)
            else:
                i = bisect.bisect_left(A, x);
                A[i] = x;
        return len(A)
    
