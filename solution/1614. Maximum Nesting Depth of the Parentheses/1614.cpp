class Solution {
public:
    int maxDepth(string s) {
        int res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else if (s[i] == ')')  {
                if (i > 0 && s[i - 1] == '(')
                    res = max(res, left);
                --left;
            } else {
                res = max(res, left);
            }
        }
        return res;
    }
};
