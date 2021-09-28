class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        
        int next[n + 1][26];
        
        for (int i = 0; i < 26; ++i)
            next[n][i] = -1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j)
                next[i][j] = next[i + 1][j];
            next[i][s[i] - 'a'] = i + 1;
        }
        
        int ans = 0;
        for (string& w : words) {
            int i = 0;
            bool flag = true;
            for (char& c : w) {
                i = next[i][c - 'a'];
                if (i == -1) {
                    flag = false;
                    break;
                }
            }
            if (flag) ++ans;
        }
        
        return ans;
    }
};
