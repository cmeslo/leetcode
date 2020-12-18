class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int N) {
        const string s = to_string(N);
        const int n = s.length();
        const int D = digits.size();
        int ans = 0;
        
        for (int i = 1; i < n; ++i)
            ans += pow(D, i);
        
        for (int i = 0; i < n; ++i) {
            bool prefix = false;
            for (const string& d : digits) {
                if (d[0] < s[i]) {
                    ans += pow(D, n - i - 1);
                } else if (d[0] == s[i]) {
                    prefix = true;
                    break;
                }
            }
            if (prefix == false) return ans;
        }
        
        return ans + 1;
    }
};
