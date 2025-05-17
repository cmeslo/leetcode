# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        min_dist, max_dist = float('inf'), -1
        
        pre = 0
        first = last = i = 0
        while head and head.next:
            nxt = head.next.val
            
            if (pre > head.val < nxt) or (pre < head.val > nxt):
                if last:
                    min_dist = min(min_dist, i - last)
                if not first:
                    first = i
                last = i
            
            pre = head.val
            head = head.next
            i += 1
            
        if min_dist == float('inf'):
            return [-1, -1]
        max_dist = last - first
        return [min_dist, max_dist]
    
