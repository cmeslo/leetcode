class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (r < n && s[r] != ' ') ++r;
            i = r;
            --r;
            while (l < r)
                swap(s[l++], s[r--]);
        }
        return s;
    }
};
