class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string& w = words[i];
            int n = w.size();
            vector<string> prefix(n + 1), suffix(n + 1);
            for (int j = 0; j <= n; ++j) {
                prefix[j] = w.substr(0, j);
                suffix[j] = w.substr(j, n - j);
            }
            for (string& pre : prefix)
                for (string& suf : suffix)
                    m[pre + '_' + suf] = i;
        }
        // m.erase("_");
    }
    
    int f(string prefix, string suffix) {
        auto it = m.find(prefix + '_' + suffix);
        return it == m.end() ? -1 : it->second;
    }
    
private:
    unordered_map<string, int> m;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
