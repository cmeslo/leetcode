# 127. Word Ladder

## BFS

用 BFS 搜索 shortest path

```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(begin(wordList), end(wordList));
    if (!words.count(endWord)) return 0;

    int ans = 0;
    int len = beginWord.length();

    queue<string> q;
    words.erase(beginWord);
    q.push(beginWord);

    while (!q.empty()) {
        ++ans;
        int size = q.size();
        while (size--) {
            auto word = q.front(); q.pop();
            for (int i = 0; i < len; ++i) {
                char tmp = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (word == endWord) return ans + 1;
                    if (words.count(word)) {
                        words.erase(word);
                        q.push(word);
                    }
                }
                word[i] = tmp;
            }
        }
    }

    return 0;
}
```
