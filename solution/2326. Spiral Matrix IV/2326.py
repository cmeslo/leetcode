# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        res = [[-1] * n for _ in range(m)]
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d = 0
        y, x = 0, -1
        while head:
            dy, dx = dirs[d]
            ny = y + dy
            nx = x + dx
            if not (0 <= ny < m and 0 <= nx < n and res[ny][nx] == -1):
                d = (d + 1) % 4
            dy, dx = dirs[d]
            y += dy
            x += dx
            res[y][x] = head.val
            head = head.next
        return res
        
