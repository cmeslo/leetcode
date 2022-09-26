class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {};
        vector<int> last(26);
        int n = S.length();
        for (int i = 0; i < n; ++i)
            last[S[i] - 'a'] = i;
        
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        
        return ans;
    }
};
