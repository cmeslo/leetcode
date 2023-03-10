# 609. Find Duplicate File in System

## Solution: hash map

### 寫法一： ```>>```

```cpp
vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> m;

    for (string& path : paths) {
        istringstream iss(path);
        string dir_path, info;
        iss >> dir_path;
        while (iss >> info) {
            int i = info.find('(');
            string filename = info.substr(0, i);
            string content = info.substr(i);
            m[content].push_back(dir_path + '/' + filename);
        }
    }

    vector<vector<string>> res;
    for (auto it : m) {
        vector<string> cur;
        if (it.second.size() > 1)
            res.push_back(it.second);
    }
    return res;
}
```

### 寫法二： ```getline```

```cpp
vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> m;

    for (string& path : paths) {
        istringstream ss(path);
        string basename, file;
        getline(ss, basename, ' ');
        while (getline(ss, file, ' ')) {
            int l = file.find('('), r = file.find(')');
            string content = file.substr(l + 1, r - l - 1);
            string filename = file.substr(0, l);
            m[content].push_back(basename + '/' + filename);
        }
    }

    vector<vector<string>> ans;
    for (auto& [content, path] : m)
        if (path.size() > 1)
            ans.push_back(path);
    return ans;
}
```
