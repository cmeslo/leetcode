class Solution {
public:
    int countVowelPermutation(int n) {
        memo_.resize(5, vector<long>(n + 1));
        long ans = 0;
        ans += helper('a', n);
        ans += helper('e', n);
        ans += helper('i', n);
        ans += helper('o', n);
        ans += helper('u', n);
        return ans % kMod_;
    }
    
private:
    const int kMod_ = 1e9 + 7;
    vector<vector<long>> memo_;
    unordered_map<char, int> m_ = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    
    long helper(const char c, int n) {
        if (n == 1) return 1;
        int i = m_[c];
        if (memo_[i][n]) return memo_[i][n];
        if (c == 'a') return memo_[i][n] = helper('e', n - 1) % kMod_;
        if (c == 'e') return memo_[i][n] = (helper('a', n - 1)
                                          + helper('i', n - 1)) % kMod_;
        if (c == 'i') return memo_[i][n] = (helper('a', n - 1)
                                          + helper('e', n - 1)
                                          + helper('o', n - 1)
                                          + helper('u', n - 1)) % kMod_;
        if (c == 'o') return memo_[i][n] = (helper('i', n - 1)
                                          + helper('u', n - 1)) % kMod_;
        if (c == 'u') return memo_[i][n] = helper('a', n - 1) % kMod_;
        return 0;
    }
};
