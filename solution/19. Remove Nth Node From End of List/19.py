# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        
        tail = dummy
        while n > 0:
            tail = tail.next
            n -= 1
        
        pre = dummy
        while tail.next:
            pre = pre.next
            tail = tail.next
        
        pre.next = pre.next.next
        
        return dummy.next
    
