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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int n = lists.size();
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            n = (n + 1) / 2;
        }
        return lists[0];
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        
        ListNode dummy(0);
        auto* tail = &dummy;
        while (l1 && l2) {
            auto& tmp = l1->val < l2->val ? l1 : l2;
            tail = tail->next = tmp;
            tmp = tmp->next;
        }
        auto& tmp = l1 ? l1 : l2;
        while (tmp) {
            tail = tail->next = tmp;
            tmp = tmp->next;
        }
        return dummy.next;
    }
};
