class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                a = max(0, a - 1);
            } else {
                s[a] = s[i];
                a++;
            }
        }
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '#') {
                b = max(0, b - 1);
            } else {
                t[b] = t[i];
                b++;
            }
        }
        if (a != b) return false;
        for (int i = 0; i < a; ++i) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};
