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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int y = 0, x = -1;
        int dy = 0, dx = 1;
        for (; head; head = head->next) {
            int ny = y + dy;
            int nx = x + dx;
            if (ny < 0 || ny >= m || nx < 0 || nx >= n || res[ny][nx] != -1) {
                swap(dy, dx);
                dx = -dx;
            }
            y += dy;
            x += dx;
            res[y][x] = head->val;
        }
        return res;
    }
};

// dy, dx
//  0,  1
//  1,  0
//  0, -1
// -1,  0

// swap(dy, dx)
// dx = -dx
