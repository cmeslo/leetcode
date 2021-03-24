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
        int p = -1;
        for (int i = 0; i < lists.size(); ++i) {
            if (!lists[i]) continue;
            if (p == -1 || lists[i]->val < lists[p]->val)
                p = i;
        }
        if (p == -1) return nullptr;
        
        auto* head = lists[p];
        if (head) {
            lists[p] = lists[p]->next;
            head->next = mergeKLists(lists);
        }
        return head;
    }
};
