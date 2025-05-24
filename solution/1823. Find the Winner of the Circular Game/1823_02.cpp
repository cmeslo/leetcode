class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        
        while (q.size() > 1) {
            int cnt = k;
            while (cnt-- > 1) {
                int x = q.front(); q.pop();
                q.push(x);
            }
            q.pop();
        }
        return q.front();
    }
};


// 1 2 3 4 5
