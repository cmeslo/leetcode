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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {INT_MAX, -1};
        
        int min_c = 0, last = 0;
        int pre = 0;
        for (int i = 0; head && head->next; ++i, head = head->next) {
            int next = head->next->val;
            if ((pre < head->val && head->val > next) || (pre > head->val && head->val < next)) {
                if (last)
                    res[0] = min(res[0], i - last);
                if (!min_c)
                    min_c = i;
                last = i;
            }
            pre = head->val;
        }
        
        if (res[0] == INT_MAX) return {-1, -1};
        res[1] = last - min_c;
        return res;
    }
};
