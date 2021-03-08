# 127. Word Ladder

## Solution1 - BFS

用 BFS 搜索 shortest path.

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

Time complexity: ```O(N * 26 * l) = O(N * l)```


## Solution2 - Bidirectional BFS

兩端同時擴展的BFS，可以有效縮小擴展的寛度。

```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(begin(wordList), end(wordList));
    if (!dict.count(endWord)) return 0;

    int step = 0;
    int len = beginWord.length();
    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};

    while (!q1.empty() && !q2.empty()) {
        if (q1.size() > q2.size()) // 先擴展size較小的queue
            swap(q1, q2);

        ++step;
        unordered_set<string> q;
        for (string word : q1) {
            for (int i = 0; i < len; ++i) {
                char tmp = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (q2.count(word)) return step + 1;
                    if (dict.count(word)) {
                        dict.erase(word);
                        q.insert(word);
                    }
                }
                word[i] = tmp;
            }
        }
        swap(q1, q);
    }

    return 0;
}
```

Time complexity: ```O(N * 26 * l) = O(N * l)```

reference: https://zxi.mytechroad.com/blog/searching/127-word-ladder/
