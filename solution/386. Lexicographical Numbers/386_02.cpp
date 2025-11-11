class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int x = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = x;
            if (x * 10 <= n) {
                x *= 10;
            } else {
                while (x + 1 > n || (x % 10 == 9))
                    x /= 10;
                x += 1;
            }
        }
        return res;
    }
};
