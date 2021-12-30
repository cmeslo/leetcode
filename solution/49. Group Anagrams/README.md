# 49. Group Anagrams

## Solution: Sort + hashmap

### 寫法一：

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& w : strs) {
        string key = w;
        sort(key.begin(), key.end());
        groups[key].push_back(w);
    }

    vector<vector<string>> ans;
    for (auto it : groups) {
        ans.push_back(it.second);
    }
    return ans;
}
```

### 寫法二：Counting Sort

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& w : strs) {
        string key = w;
        groups[countingSort(key)].push_back(w);
    }

    vector<vector<string>> ans;
    for (auto it : groups)
        ans.push_back(it.second);

    return ans;
}

string countingSort(const string& word) {
    vector<int> counter(26);
    for (const char& c : word)
        ++counter[c - 'a'];

    string res;
    for (int i = 0; i < 26; ++i)
        res += string(counter[i], i + 'a');

    return res;
}
```

### 寫法三：（推薦）

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> m;

    for (int i = 0; i < strs.size(); ++i) {
        string key = strs[i];
        sort(key.begin(), key.end());
        m[key].push_back(i);
    }

    for (auto& kv : m) {
        ans.push_back({});
        for (int i : kv.second)
            ans.back().push_back(strs[i]);
    }
    return ans;
}
```
