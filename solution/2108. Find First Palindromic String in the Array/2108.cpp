class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& w : words) {
            int l = 0, r = w.size() - 1;
            while (l < r && w[l] == w[r]) {
                l++;
                r--;
            }
            if (l >= r) return w;
        }
        return "";
    }
};
