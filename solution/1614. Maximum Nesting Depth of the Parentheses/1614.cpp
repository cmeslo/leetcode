class Solution {
public:
    int maxDepth(string s) {
        int res = 0, left = 0;
        for (char& c : s) {
            if (c == '(')
                res = max(res, ++left);
            else if (c == ')')
                --left;
        }
        return res;
    }
};
