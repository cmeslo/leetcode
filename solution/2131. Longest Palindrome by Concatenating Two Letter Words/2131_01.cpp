class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (string& w : words) m[w]++;
        
        bool middle = false;
        int res = 0;
        for (auto& [w, cnt] : m) {
            if (cnt == 0) continue;
            if (w[0] == w[1]) {
                if (cnt % 2) {
                    if (!middle) {
                        middle = true;
                        res += 2;
                    }
                    cnt--;
                }
                res += cnt * 2;
                cnt = 0;
            } else {
                string mirror = w;
                reverse(mirror.begin(), mirror.end());
                if (m.count(mirror)) {
                    res += min(cnt, m[mirror]) * 4;
                    cnt = m[mirror] = 0;
                }
            }
        }
        return res;
    }
};
