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
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int y = 0, x = -1;
        for (int i = 1; i <= m * n && head; ++i) {
            int next_y = y + dirs[d][0];
            int next_x = x + dirs[d][1];
            if (next_y < 0 || next_y >= m || next_x < 0 || next_x >= n || ans[next_y][next_x] != -1)
                d = (d + 1) % 4;
            y = y + dirs[d][0];
            x = x + dirs[d][1];
            ans[y][x] = head->val;
            head = head->next;
        }
        return ans;
    }
};
