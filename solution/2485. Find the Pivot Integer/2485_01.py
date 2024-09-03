class Solution:
    def pivotInteger(self, n: int) -> int:
        total = n * (1 + n) / 2
        l, r = 1, n
        while l <= r:
            mid = (l + r) // 2
            sum_l = mid * (1 + mid) / 2
            sum_r = total - sum_l + mid
            if sum_l == sum_r:
                return mid
            if sum_l < sum_r:
                l = mid + 1
            else:
                r = mid - 1
        return -1
    
