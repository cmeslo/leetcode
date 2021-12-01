# 126. Word Ladder II

## BFS（寫法一）

使用額外空間 ```dist```，來記錄並判斷、同一距離出現同一字符串時，才加到鏈裡。

```cpp
// Your runtime beats 94.39 % of cpp submissions.
// Your memory usage beats 85.77 % of cpp submissions.

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
```

## BFS（寫法二）

用 ```set``` 作為 BFS 的容器，同時利用 ```dict``` 去確保不會走回頭路。

```cpp
// Your runtime beats 94.39 % of cpp submissions.
// Your memory usage beats 93.81 % of cpp submissions.

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
```
