class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        
        vector<int> suffixB(n);
        suffixB[n - 1] = s[n - 1] == 'a';
        for (int i = n - 2; i >= 0; --i) {
            suffixB[i] = suffixB[i + 1] + (s[i] == 'a');
        }
        
        vector<int> prefixA(n);
        prefixA[0] = s[0] == 'b';
        for (int i = 1; i < n; ++i) {
            prefixA[i] = prefixA[i - 1] + (s[i] == 'b');
        }
        
        int res = min(prefixA[n - 1], suffixB[0]);
        for (int i = 0; i + 1 < n; ++i) {
            res = min(res, prefixA[i] + suffixB[i + 1]);
        }
        return res;
    }
};



// aababbab
//   i
