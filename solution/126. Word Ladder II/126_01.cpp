class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        
        unordered_map<string, vector<string>> children;
        unordered_map<string, int> dist {{beginWord, 1}};
        queue<string> q;
        dict.erase(beginWord);
        dict.erase(endWord);
        q.push(beginWord);
        
        const int len = beginWord.length();
        bool found = false;
        int step = 0;
        while (!q.empty() && !found) {
            ++step;
            for (int size = q.size(); size > 0; --size) {
                const string p = q.front(); q.pop();
                string w = p;
                for (int i = 0; i < len; ++i) {
                    const char c = w[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        if (c == j) continue;
                        w[i] = j;
                        if (w == endWord) {
                            children[p].push_back(w);
                            found = true;
                        } else if (!found && dist.count(w) && step + 1 == dist[w]) {
                            children[p].push_back(w);
                        }
                        
                        if (!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        children[p].push_back(w);
                        dist[w] = step + 1;
                    }
                    w[i] = c;
                }
            }
        }
        
        vector<vector<string>> ans;
        if (found) {
            vector<string> path{beginWord};
            getPath(beginWord, endWord, children, path, ans);
        }
        return ans;
    }
    
private:
    void getPath(const string& word,
                 const string& endWord,
                 unordered_map<string, vector<string>>& children,
                 vector<string>& cur,
                 vector<vector<string>>& ans) {
        
        if (word == endWord) {
            ans.push_back(cur);
            return;
        }
        
        if (!children.count(word)) return;
        for (const string& child : children[word]) {
            cur.push_back(child);
            getPath(child, endWord, children, cur, ans);
            cur.pop_back();
        }
    }
};
