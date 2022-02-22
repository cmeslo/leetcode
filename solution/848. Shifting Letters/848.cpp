class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int cnt = 0;
        for (int i = shifts.size() - 1; i >= 0; --i) {
            cnt = (cnt + shifts[i]) % 26;
            s[i] = (s[i] - 'a' + cnt) % 26 + 'a';
        }
        return s;
    }
};
