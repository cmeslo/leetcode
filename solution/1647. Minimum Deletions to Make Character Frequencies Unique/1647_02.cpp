class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (char& c : s)
            freq[c - 'a']++;
        
        int keep = 0, mn = INT_MAX;
        sort(freq.rbegin(), freq.rend());
        for (int f : freq) {
            if (f == 0 || mn == 0) break;
            mn = min(f, mn - 1);
            keep += mn;
        }
        return s.size() - keep;
    }
};

// aaabbbccde
// 3 3 2 1 1
// 3 2 1 0 0
