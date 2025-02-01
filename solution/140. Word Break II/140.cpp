class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for (string& word : wordDict) {
            D.insert(word);
        }
        
        dfs(s, 0);
        return res;
    }
    
private:
    int n;
    unordered_set<string> D;
    vector<string> res;
    vector<string> cur;
    
    void dfs(const string& s, int i) {
        if (i == n) {
            string tmp;
            for (string& w : cur) {
                tmp += w + ' ';
            }
            tmp.pop_back();
            res.push_back(tmp);
        }
        for (int j = i; j < n; ++j) {
            string sub = s.substr(i, j - i + 1);
            if (D.count(sub)) {
                cur.push_back(sub);
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }
};

// [x x x] x x x x
