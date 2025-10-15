
# 2326. Spiral Matrix IV

## Python

寫法二

```py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        res = [[-1] * n for _ in range(m)]
        dy, dx = 0, 1
        y, x = 0, 0
        while head:
            res[y][x] = head.val
            if not (0 <= y + dy < m and 0 <= x + dx < n and res[y + dy][x + dx] == -1):
                dy, dx = dx, -dy
            y += dy
            x += dx
            head = head.next
        return res
```
