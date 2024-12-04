class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0;
        vector<int> cnt(1 << 10);
        cnt[0] = 1;
        int state = 0;
        for (char& c : word) {
            state ^= (1 << (c - 'a'));
            res += cnt[state];
            for (int i = 0; i < 10; ++i) {
                res += cnt[state ^ (1 << i)];
            }
            ++cnt[state];
        }
        return res;
    }
};
