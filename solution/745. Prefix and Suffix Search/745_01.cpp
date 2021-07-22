class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int index = 0;
        for (string& w : words) {
            int n = w.length();
            vector<string> prefixes(n + 1, "");
            vector<string> suffixes(n + 1, "");
            for (int i = 1; i <= n; ++i) {
                prefixes[i] = prefixes[i - 1] + w[i - 1];
                suffixes[i] = w[n - i] + suffixes[i - 1];
            }
            for (string& pre : prefixes)
                for (string& suf : suffixes)
                    filter_[pre + '_' + suf] = index;
            index++;
        }
    }
    
    int f(string prefix, string suffix) {
        auto it = filter_.find(prefix + '_' + suffix);
        if (it != filter_.end())
            return it->second;
        return -1;
    }
    
private:
    unordered_map<string, int> filter_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
