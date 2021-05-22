class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if ((n - k + 1) * k < (1 << k)) return false;
        
        unordered_set<string> codes;
        for (int i = 0; i + k - 1 < n; ++i)
            codes.insert(s.substr(i, k));
        
        return codes.size() == (1 << k);
    }
};
