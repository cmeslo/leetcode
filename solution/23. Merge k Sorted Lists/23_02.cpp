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
        auto comp = [&](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        for (auto node : lists)
            if (node) pq.push(node);
        
        ListNode dummy(0);
        auto tail = &dummy;
        while (!pq.empty()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return dummy.next;
    }
};
