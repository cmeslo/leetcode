class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(A, l, r):
            if l >= r: return
            
            m = (l + r) // 2
            merge_sort(A, l, m)
            merge_sort(A, m + 1, r)
            
            n = r - l + 1
            B = [0] * n
            
            i, j = l, m + 1
            k = 0
            
            while i <= m and j <= r:
                if A[i] < A[j]:
                    B[k] = A[i]
                    i += 1
                else:
                    B[k] = A[j]
                    j += 1
                k += 1
                
            while i <= m:
                B[k] = A[i]
                i += 1
                k += 1
                
            while j <= r:
                B[k] = A[j]
                j += 1
                k += 1
            
            for k in range(n):
                A[l + k] = B[k]
            
        merge_sort(nums, 0, len(nums) - 1)
        return nums
    
