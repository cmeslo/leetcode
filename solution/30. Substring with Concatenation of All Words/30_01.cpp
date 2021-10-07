class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size(), l = words[0].size();
        if (s.size() < n * l) return {};
        
        unordered_map<string, int> f;
        for (const string& word : words) ++f[word];
        
        vector<int> ans;
        for (int i = 0; i <= s.size() - n * l; ++i) {
            int count = 0;
            unordered_map<string, int> seen;
            for (int j = 0; j < n; ++j) {
                string w = s.substr(i + j * l, l);
                auto it = f.find(w);
                if (it == f.end()) break;
                if (++seen[w] > it->second) break;
                ++count;
            }
            if (count == n)
                ans.push_back(i);
        }
        return ans;
    }
};
