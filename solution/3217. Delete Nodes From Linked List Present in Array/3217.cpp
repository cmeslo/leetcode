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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> A(nums.begin(), nums.end());
        
        ListNode dummy;
        dummy.next = head;
        auto p = &dummy;
        while (p && p->next) {
            if (A.count(p->next->val))
                p->next = p->next->next;
            else
                p = p->next;
        }
        return dummy.next;
    }
};
