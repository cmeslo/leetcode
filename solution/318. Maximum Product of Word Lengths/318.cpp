class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            int code = 0;
            for (char& c : words[i])
                code |= (1 << (c - 'a'));
            A[i] = code;
        }
        
        size_t ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((A[i] & A[j]) == 0)
                    ans = max(ans, words[i].size() * words[j].size());
            }
        }
        return ans;
    }
};
