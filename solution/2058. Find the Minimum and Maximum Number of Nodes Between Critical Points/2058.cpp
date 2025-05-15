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
        
        int mn_c = -1, mx_c = -1, pre_c = -1;
        int pre = head->val;
        head = head->next;
        int j = 1, i = 1;
        
        while (head && head->next) {
            int next = head->next->val;
            if ((pre < head->val && head->val > next) || (pre > head->val && head->val < next)) {
                if (pre_c != -1)
                    res[0] = min(res[0], i - pre_c);
                mx_c = pre_c = i;
                if (mn_c == -1)
                    mn_c = i;
            }
            pre = head->val;
            head = head->next;
            ++i;
        }
        
        if (mn_c == mx_c) return {-1, -1};
        res[1] = mx_c - mn_c;
        return res;
    }
};
