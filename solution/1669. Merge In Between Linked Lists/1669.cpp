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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto p = list1, A = list1, B = list1;
        for (int i = 0; i <= b; ++i, p = p->next) {
            if (i == a - 1)
                A = p;
            if (i == b)
                B = p->next;
        }
        A->next = list2;
        
        // find tail of list2
        p = list2;
        while (p->next) {
            p = p->next;
        }
        p->next = B;
        
        return list1;
    }
};

// 0 1  2 3 4 5  6 7 8 9 ...
// x x [x x x x] x x x x ...
//   A  a     b  B
