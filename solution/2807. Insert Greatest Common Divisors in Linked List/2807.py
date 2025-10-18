# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p = head;
        while p and p.next:
            # p.next, p = ListNode(gcd(p.val, p.next.val), p.next), p.next
            p.next = ListNode(gcd(p.val, p.next.val), p.next)
            p = p.next.next
        return head
    
