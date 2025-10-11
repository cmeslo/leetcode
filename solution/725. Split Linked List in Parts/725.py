# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = 0
        p = head
        while p:
            n += 1
            p = p.next
        
        l, r = n // k, n % k
        
        res = [None] * k
        
        tail = None
        p = head
        for i in range(k):
            if not p:
                break
            
            res[i] = p
            
            for _ in range(l):
                tail = p
                p = p.next
            
            if r > 0:
                r -= 1
                tail = p
                p = p.next
            
            if tail:
                tail.next = None
        
        return res
    
