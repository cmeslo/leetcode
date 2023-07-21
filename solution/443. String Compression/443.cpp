class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        for (int j = 1, len = 1; j <= n; ++j, ++len) {
            if (j == n || chars[j] != chars[j - 1]) {
                chars[i++] = chars[j - 1];
                if (len > 1) {
                    string num = to_string(len);
                    for (char& x : num)
                        chars[i++] = x;
                }
                len = 0;
            }
        }
        return i;
    }
};
