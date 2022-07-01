/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy;
        auto cur = &dummy;
        
        while (head) {
            auto tmp = head->next;
            if (cur->val > head->val) cur = &dummy;
            while (cur->next && cur->next->val <= head->val)
                cur = cur->next;
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        
        return dummy.next;
    }
};

// x -> 1 -> 3 -> 4 -> 2 -> ...
//      ^    ^         ^
//      cur            head

// x -> 1 -> 3 -> 4 -> 2 -> 5 -> ...
//      ^    ^         ^
//      cur            head

// x -> 4 -> 2 -> 1 -> 3
// ^    ^
// cur
