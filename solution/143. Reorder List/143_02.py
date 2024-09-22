# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        def reverse(node):
            pre = None
            while node:
                nxt = node.next
                node.next = pre
                pre = node
                node = nxt
            return pre
        
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        p1, p2 = head, reverse(slow.next)
        slow.next = None
        
        while p1 and p2:
            nxt1, nxt2 = p1.next, p2.next
            p1.next = p2
            p2.next = nxt1
            p1, p2 = nxt1, nxt2
        
