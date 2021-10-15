class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), k = n / 4;
        int res = n, i = 0;
        
        unordered_map<int, int> count;
        for (char& c : s)
            ++count[c];
        
        for (int j = 0; j < n; ++j) {
            count[s[j]]--;
            while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                res = min(res, j - i + 1);
                count[s[i++]]++;
            }
        }
        return res;
    }
};
