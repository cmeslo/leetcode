class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto& word : words)
            reverse(begin(word), end(word));
        
        sort(begin(words), end(words));
        
        int ans = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i] == words[i + 1].substr(0, words[i].size()))
                continue;
            ans += words[i].size() + 1;
        }
        ans += words.back().size() + 1;
        return ans;
    }
};
