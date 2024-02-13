class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        
        unordered_map<char, int> m;
        for (char& c : s) {
            if (++m[c] > (n + 1) / 2)
                return "";
        }
        
        sort(s.begin(), s.end(), [&](const char& a, const char& b) {
            return m[a] > m[b] || (m[a] == m[b] && a < b);
        });
        
        string res(n, '.');
        int i = 0;
        for (char& c : s) {
            res[i] = c;
            i += 2;
            if (i >= n)
                i = 1;
        }
        return res;
    }
};
