class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(begin(d), end(d), [&](const string& a, const string& b) {
            return (a.size() > b.size()) || (a.size() == b.size() && a < b);
        });
        
        for (const auto& word : d) {
            int i = 0;
            for (const char& c : s) {
                if (c == word[i]) ++i;
                if (i == word.size()) break;
            }
            if (i == word.size())
                return word;
        }
        
        return "";
    }
};
