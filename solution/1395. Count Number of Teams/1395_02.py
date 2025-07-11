class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        
        res = 0
        for i in range(1, n - 1):
            left_smaller = left_greater = right_smaller = right_greater = 0
            for j in range(n):
                if rating[j] < rating[i]:
                    if j < i:
                        left_smaller += 1
                    else:
                        right_smaller += 1
                if rating[i] < rating[j]:
                    if j < i:
                        left_greater += 1
                    else:
                        right_greater += 1
            res += left_smaller * right_greater + left_greater * right_smaller
        return res
    

# x x x x x x x x
#     j   i   j
