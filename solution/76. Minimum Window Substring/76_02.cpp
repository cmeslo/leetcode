class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128);
        for (char& c : t) need[c]++;
        
        int n = s.size();
        int cnt = 0, l = 0, len = n + 1;
        for (int i = 0, j = 0; j < n; ++j) {
            if (need[s[j]]-- > 0) ++cnt;
            while (cnt == t.size()) {
                if (j - i + 1 < len) {
                    l = i;
                    len = j - i + 1;
                }
                if (++need[s[i++]] > 0) --cnt;
            }
        }
        return len == n + 1 ? "" : s.substr(l, len);
    }
};
