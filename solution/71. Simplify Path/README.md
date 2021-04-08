# 71. Simplify Path

## Solution 1: 原始方法

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        
        deque<string> q;
        int i = 0;
        while (i < n) {
            if (path[i] == '/')
                ++i;
            else if (path[i] == '.')
                handleDots(path, i, q);
            else
                getName(path, i, q);
        }
        
        string ans = "/";
        while (!q.empty()) {
            ans += q.front() + (q.size() > 1 ? "/" : "");
            q.pop_front();
        }
        return ans;
    }
    
private:
    void handleDots(const string& path, int& i, deque<string>& q) {
        int n = path.size();
        // 1. 遇到 . 結尾跳過
        if (i == n - 1) {
            ++i;
            return;
        }
        // 2. 遇到 ./ 跳過
        if (i + 1 < n && path[i + 1] == '/') {
            i += 2;
            return;
        }
        // 3. 遇到 ..
        if (i + 1 < n && path[i + 1] == '.') {
            // 遇到 ..結尾 或者 ../ 就pop掉上一層目錄
            if (i + 2 >= n || path[i + 2] == '/') {
                if (!q.empty()) q.pop_back();
                i += 2;
                return;
            }
        }
        // 4. 其他情況都當成合法目錄或檔案，比如 ...
        getName(path, i, q);
    }
    
    void getName(const string& path, int& i, deque<string>& q) {
        int n = path.size();
        int j = i + 1;
        while (j < n && path[j] != '/')
            ++j;
        q.push_back(path.substr(i, j - i));
        i = j + 1;
    }
};
```

## Solution 2: 使用 stringstream 和 getline (推薦)

按 / 符號分割，再判斷要skip、push還是要pop，代碼更簡潔。

- istringstream 只讀數據，只處理 >> 符號，如 ```iss >> string```
- ostringstream 只寫數據，只處理 << 符號，如 ```oss << "test"```
- stringstream 可寫可讀。

```cpp
string simplifyPath(string path) {
    istringstream ss(path);
    string tmp;

    vector<string> q;
    while (getline(ss, tmp, '/')) {
        if (tmp == "" || tmp == ".") continue;
        if (tmp == "..") {
            if (!q.empty()) q.pop_back();
        } else {
            q.push_back(tmp);
        }
    }

    string ans;
    for (string name : q)
        ans += "/" + name;
    return ans.empty() ? "/" : ans;
}
```
