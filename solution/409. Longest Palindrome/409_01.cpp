class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        
        for (const char& c : s) freq[c]++;
        
        int ans = 0, odd = 0;
        for (auto& it : freq) {
            if (it.second % 2 == 0) {
                ans += it.second;
            } else {
                odd = 1;
                ans += it.second - 1;
            }
        }
        
        return ans + odd;
    }
};
