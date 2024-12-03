class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0;
        unordered_map<int, int> prefix;
        int mask = 0;
        prefix[0] = 1;
        for (char& c : word) {
            mask ^= (1 << (c - 'a'));
            res += prefix[mask];
            for (int i = 0; i < 10; ++i) {
                if (prefix.count(mask ^ (1 << i)))
                    res += prefix[mask ^ (1 << i)];
            }
            ++prefix[mask];
        }
        return res;
    }
};
