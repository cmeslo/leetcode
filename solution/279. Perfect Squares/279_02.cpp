class Solution {
public:
    int numSquares(int n) {
        int res = 0;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int cur = q.front(); q.pop();
                for (int i = 1; i*i <= cur; ++i) {
                    if (cur == i*i) return res + 1;
                    q.push(cur - i*i);
                }
            }
            ++res;
        }
        return n;
    }
};
