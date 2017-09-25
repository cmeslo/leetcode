/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        unordered_map<int, RandomListNode*> m;

        RandomListNode *p = head;
        while (p != NULL) {
            m[p->label] = new RandomListNode(p->label);
            p = p->next;
        }
        p = head;
        while (p != NULL) {
            if (p->next != NULL) m[p->label]->next = m[p->next->label];
            if (p->random != NULL) m[p->label]->random = m[p->random->label];
            p = p->next;
        }
        return m[head->label];
    }
};
