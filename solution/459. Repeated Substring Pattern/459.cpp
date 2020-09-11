class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        for (int k = n / 2; k > 0; --k) {
            if (n % k != 0) continue;
            string sub = s.substr(0, k);
            
            int i;
            for (i = 0; i < n; i += k)
                if (sub != s.substr(i, k)) break;
            
            if (i >= n) return true;
        }
        
        return false;
    }
};
