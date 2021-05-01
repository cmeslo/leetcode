class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        int d = -1;
        
        for (int i = 0; i < S.size(); ++i) {
            d += (S[i] == '(' ? 1 : -1);
            if (S[i] == '(' && S[i + 1] == ')')
                ans += 1 << d;
        }
        return ans;
    }
};
