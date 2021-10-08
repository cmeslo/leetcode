# 30. Substring with Concatenation of All Words

## Solution 1: Brute Force

Time: ```O(len * n)```, ```len = s.size(), n = words.size()```

```cpp
// Your runtime beats 77.80 % of cpp submissions.
// Your memory usage beats 64.70 % of cpp submissions.

vector<int> findSubstring(string s, vector<string>& words) {
    int n = words.size(), l = words[0].size();
    if (s.size() < n * l) return {};

    unordered_map<string, int> f;
    for (const string& word : words) ++f[word];

    vector<int> ans;
    for (int i = 0; i <= s.size() - n * l; ++i) {
        int count = 0;
        unordered_map<string, int> seen;
        for (int j = 0; j < n; ++j) {
            string w = s.substr(i + j * l, l);
            auto it = f.find(w);
            if (it == f.end()) break;
            if (++seen[w] > it->second) break;
            ++count;
        }
        if (count == n)
            ans.push_back(i);
    }
    return ans;
}
```

## Solution 2: Two Pointers / Sliding Windows

Time: ```O(l * n/l) = O(n)```, ```n = words.size(), l = words[0].size()```

```cpp
// Your runtime beats 96.43 % of cpp submissions.
// Your memory usage beats 90.24 % of cpp submissions.

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
```
