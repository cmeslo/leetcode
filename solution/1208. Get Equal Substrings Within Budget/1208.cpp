class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int n = s.size();
        int res = 0;
        for (int j = 0, i = 0; i < n; ++i) {
            int diff = abs(s[i] - t[i]);
            while (diff > maxCost) {
                maxCost += abs(s[j] - t[j]);
                ++j;
            }
            if (diff <= maxCost) {
                res = max(res, i - j + 1);
                maxCost -= diff;
            }
        }
        return res;
    }
};

// a b c d
// b c d f
// 1 1 1 2
