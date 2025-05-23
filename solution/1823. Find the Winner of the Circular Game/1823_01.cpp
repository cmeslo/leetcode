class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;
        
        vector<int> next(n);
        for (int i = 0; i < n - 1; ++i)
            next[i] = i + 1;
        next[n - 1] = 0;
        
        int cnt = n, i = 0;
        while (cnt--) {
            int pre = i;
            for (int j = 0; j < k - 1; ++j) {
                pre = i;
                i = next[i];
            }
            next[pre] = next[i];
            i = next[i];
        }
        return i + 1;
    }
};


// 0 1 2
// 1 2 0
