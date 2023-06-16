class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        vector<int> seen(n * n + 1);
        queue<int> q;
        seen[1] = 1;
        q.push(1);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front(); q.pop();
                if (node == n * n) return res;
                for (int next = node + 1; next <= min(node + 6, n * n); ++next) {
                    if (seen[next]++) continue;
                    int i = (next - 1) / n;
                    int j = (next - 1) % n;
                    int y = n - 1 - i;
                    int x = i % 2 == 0 ? j : n - 1 - j;
                    q.push(board[y][x] != -1 ? board[y][x] : next);
                }
            }
            res++;
        }
        return -1;
    }
};
