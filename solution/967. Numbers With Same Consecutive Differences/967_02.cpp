class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int len = 2; len <= n; ++len) {
            vector<int> tmp;
            for (int x : res) {
                int y = x % 10;
                if (y - k >= 0)
                    tmp.push_back(x * 10 + y - k);
                if (k > 0 && y + k <= 9)
                    tmp.push_back(x * 10 + y + k);
            }
            res = tmp;
        }
        return res;
    }
};
