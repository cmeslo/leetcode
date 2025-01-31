class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        for (char& c : letters) ++cnt[c - 'a'];
        res = 0;
        dfs(words, score, 0, 0);
        return res;
    }
    
private:
    int n;
    int cnt[26];
    int res;
    
    void dfs(vector<string>& words, vector<int>& score, int i, int sum) {
        if (i == n) {
            res = max(res, sum);
            return;
        }
        
        // 1. skip it
        dfs(words, score, i+1, sum);
        
        // 2. take it
        for (int j = i; j < n; ++j) {
            bool ok = true;
            int s = 0;
            for (char& c : words[i]) {
                if (--cnt[c - 'a'] < 0) ok = false;
                s += score[c - 'a'];
            }
            
            if (ok) dfs(words, score, j + 1, sum + s);
            
            for (char& c : words[i]) ++cnt[c - 'a'];
        }
    }
};
