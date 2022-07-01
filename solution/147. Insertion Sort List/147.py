# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        dummy = ListNode(0)
        pre = dummy
        while head:
            temp = head.next
            if head.val < pre.val:
                pre = dummy
            while pre.next and pre.next.val < head.val:
                pre = pre.next
            head.next = pre.next
            pre.next = head
            head = temp
        return dummy.next
        
