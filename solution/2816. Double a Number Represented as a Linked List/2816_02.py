# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.val > 4:
            head = ListNode(0, head)
            
        p = head;
        while p:
            p.val = p.val * 2 % 10
            if p.next and p.next.val > 4:
                p.val += 1
            p = p.next
        return head
    
