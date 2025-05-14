# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p1, p2 = head, head.next
        
        while p2:
            if p2.val != 0:
                p1.val += p2.val
            else:
                p1.next = p2 if p2.next else None
                p1 = p2
            p2 = p2.next
        
        return head
    
