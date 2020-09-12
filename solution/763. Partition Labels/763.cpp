class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        unordered_map<char, int> last;
        for (int i = 0; i < n; ++i)
            last[S[i]] = i;
        
        vector<int> ans;
        int l = 0, r = last[S[0]];
        for (int i = 0; i < n; ++i) {
            if (i < r) {
                r = max(r, last[S[i]]);
            } else if (i == r) {
                ans.push_back(r - l + 1);
                if (i + 1 < n) {
                    l = i + 1;
                    r = last[S[i + 1]];
                }
            }
        }
        
        return ans;
    }
};
