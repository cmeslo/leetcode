# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        s = set(nums)
        
        dummy = ListNode
        dummy.next = head
        p = dummy
        
        while p and p.next:
            if p.next.val in s:
                p.next = p.next.next
            else:
                p = p.next
        return dummy.next
    
