class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(begin(words), end(words));
        
        for (auto word : s)
            for (int i = 1; i < word.size(); ++i)
                s.erase(word.substr(i));
        
        int ans = 0;
        for (auto word : s)
            ans += word.size() + 1;
        return ans;
    }
};
