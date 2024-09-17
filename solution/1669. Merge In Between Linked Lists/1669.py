# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        p = A = B = list1
        
        for i in range(b + 1):
            if i == a - 1:
                A = p
            if i == b:
                B = p.next
            p = p.next
        A.next = list2

        p = list2
        while p.next:
            p = p.next
        p.next = B

        return list1
