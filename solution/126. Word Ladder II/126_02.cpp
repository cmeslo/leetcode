class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        
        const int len = endWord.length();
        unordered_set<string> q, tmp;
        unordered_map<string, vector<string>> children;
        q.insert(beginWord);
        bool found = false;
        
        while (!q.empty() && !found) {
            for (const string& word : q)
                dict.erase(word);
            
            for (string parent : q) {
                string w = parent;
                for (int i = 0; i < len; ++i) {
                    const char c = w[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        if (c == j) continue;
                        w[i] = j;
                        if (!dict.count(w)) continue;
                        children[parent].push_back(w);
                        if (w == endWord)
                            found = true;
                        else
                            tmp.insert(w);
                    }
                    w[i] = c;
                }
            }
            q.clear();
            swap(q, tmp);
        }
        
        vector<vector<string>> ans;
        if (found) {
            vector<string> cur{beginWord};
            getPaths(beginWord, endWord, children, cur, ans);
        }
        return ans;
    }
    
private:
    void getPaths(const string& word,
                 const string& endWord,
                 unordered_map<string, vector<string>>& children,
                 vector<string>& cur,
                 vector<vector<string>>& ans) {
        
        if (word == endWord) {
            ans.push_back(cur);
            return;
        }
        
        if (!children.count(word)) return;
        for (const string& child : children.at(word)) {
            cur.push_back(child);
            getPaths(child, endWord, children, cur, ans);
            cur.pop_back();
        }
    }
};
