class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size(), l = words[0].size();
        
        unordered_map<string, int> f;
        for (const string& w : words) ++f[w];
        
        vector<int> ans;
        for (int k = 0; k < l; ++k) {
            int count = 0;
            unordered_map<string, int> seen;
            int i = k, j = k;
            while (j + l <= s.size()) {
                string w = s.substr(j, l);
                if (f.find(w) == f.end()) {
                    seen.clear();
                    count = 0;
                    j += l;
                    i = j;
                } else if (seen[w] < f[w]) {
                    ++seen[w];
                    ++count;
                    j += l;
                } else if (seen[w] == f[w]) {
                    --seen[s.substr(i, l)];
                    --count;
                    i += l;
                }
                
                if (count == n) {
                    ans.push_back(i);
                    --seen[s.substr(i, l)];
                    --count;
                    i += l;
                }
            }
        }
        return ans;
    }
};
