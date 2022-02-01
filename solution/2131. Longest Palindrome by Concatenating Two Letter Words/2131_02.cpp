class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<vector<int>> m(26, vector<int>(26));
        for (string& w : words) {
            int a = w[0] - 'a', b = w[1] - 'a';
            if (m[b][a]) {
                ans += 4;
                m[b][a]--;
            } else {
                m[a][b]++;
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (m[i][i]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
