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
        // insert nodes
        RandomListNode *p = head;
        while (p != NULL) {
            RandomListNode *temp = new RandomListNode(p->label);
            temp->next = p->next;
            p->next = temp;
            p = temp->next;
        }
        
        // copy random
        p = head;
        while (p != NULL) {
            RandomListNode *temp = p->next;
            if (p->random != NULL) {
                temp->random = p->random->next;
            }
            p = temp->next;
        }
        
        // split two links
        RandomListNode *dup = head == NULL ? NULL : head->next;
        p = head;
        while (p != NULL) {
            RandomListNode *temp = p->next;
            p->next = temp->next;
            if (temp->next != NULL) {
                temp->next = temp->next->next;
            }
            p = p->next;
        }
        return dup;
    }
};
