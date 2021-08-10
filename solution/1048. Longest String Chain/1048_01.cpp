class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [&](string &a, string& b) {
            return a.size() < b.size();
        });
        
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (words[j].size() == words[i].size()) continue;
                if (words[j].size() + 1 < words[i].size()) break;
                if (isPredecessor(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
    
private:
    bool isPredecessor(const string& A, const string& B) {
        if (A.size() + 1 != B.size()) return false;
        
        int a = 0, b = 0;
        int diff = 0;
        while (a < A.size()) {
            if (A[a] != B[b]) {
                if (++diff > 1) break;
                ++b;
            } else {
                ++a, ++b;
            }
        }
        return diff <= 1;
    }
};
