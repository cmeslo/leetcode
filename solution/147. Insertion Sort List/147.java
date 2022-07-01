/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode pre = dummy;
        while (head != null) {
            ListNode temp = head.next;
            if (head.val < pre.val) pre = dummy;
            while (pre.next != null && pre.next.val < head.val)
                pre = pre.next;
            head.next = pre.next;
            pre.next = head;
            head = temp;
        }
        return dummy.next;
    }
}
