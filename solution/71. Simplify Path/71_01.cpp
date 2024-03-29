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
