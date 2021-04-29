class Solution {
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size() - 1);
    }
    
private:
    int score(string& s, int l, int r) {
        if (l + 1 == r) return 1;
        int cnt = 0;
        for (int i = l; i < r; ++i) {
            if (s[i] == '(')
                ++cnt;
            else
                --cnt;
            if (cnt == 0)
                return score(s, l, i) + score(s, i + 1, r);
        }
        return 2 * score(s, l + 1, r - 1);
    }
};
