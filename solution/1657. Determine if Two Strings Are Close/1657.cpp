class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        
        vector<int> w1(26), w2(26);
        for (char& c : word1)
            ++w1[c - 'a'];
        for (char& c : word2) {
            if (w1[c - 'a'] == 0) return false;
            ++w2[c - 'a'];
        }
        
        sort(begin(w1), end(w1));
        sort(begin(w2), end(w2));
        
        return w1 == w2;
    }
};
