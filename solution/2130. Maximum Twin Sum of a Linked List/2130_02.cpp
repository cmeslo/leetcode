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
    int pairSum(ListNode* head) {
        // 1. find middle
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto p = slow->next;
        slow->next = nullptr;
        
        // 2. reverse second part
        ListNode* pre = nullptr;
        while (p) {
            auto t = p->next;
            p->next = pre;
            pre = p;
            p = t;
        }
        auto head2 = pre;
        
        // 3. sum two linked list
        int res = 0;
        while (head) {
            res = max(res, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return res;
    }
};


// x x x x
//   s
//       f

// x x x x
// p t
