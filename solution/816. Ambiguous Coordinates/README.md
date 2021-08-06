# 816. Ambiguous Coordinates

## Solution:

### 寫法一：

```cpp
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        s.erase(s.begin());
        s.pop_back();
        
        int n = s.size();
        vector<string> ans;
        for (int len = 1; len < n; ++len) { // 用 "," 分割左、右兩邊
            vector<string> left = getValidSet(s.substr(0, len));
            if (left.empty()) continue;
            vector<string> right = getValidSet(s.substr(len));
            if (right.empty()) continue;
            for (string& l : left) {
                for (string& r : right) {
                    ans.push_back('(' + l + ", " + r + ')');
                }
            }
        }
        return ans;
    }
    
private:
     // 根據字符串，獲得合法數字的集合
    vector<string> getValidSet(string str) {
        if (str.empty()) return {};
        
        int n = str.size();
        vector<string> nums;
        
         // 不添加 "."，看看是否合法
        if (isValid(str)) nums.push_back(str);
        
        // 分割成左、右兩邊、中間加個 "."，看看是否合法
        for (int len = 1; len < n; ++len) {
            string cur = str.substr(0, len) + '.' + str.substr(len);
            if (isValid(cur)) 
                nums.push_back(cur);
        }
        return nums;
    }
    
    bool isValid(string& str) {
        if (str.empty()) return false;
        
        int n = str.size();
        size_t found = str.find('.');
        if (found == string::npos) { // 沒有 "." 的情況
            if (n > 1 && str[0] == '0') // "00", "001"
                return false;
        } else { // 有 "." 的情況
            if (str[n - 1] == '0') // "0.0", "0.00", "1.0"
                return false;
            if (str[0] == '0' && str[1] != '.') // "00.01", "01.01"
                return false;
        }
        return true;
    }
};
```

### 寫法二 (推薦，更簡潔)：

```cpp
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i < n - 2; ++i) {
            auto A = f(s.substr(1, i)), B = f(s.substr(i + 1, n - 2 - i));
            for (auto& a : A)
                for (auto& b : B)
                    ans.push_back("(" + a + ", " + b + ")");
        }
        return ans;
    }
    
private:
    vector<string> f(string s) {
        int n = s.size();
        if (n == 0) return {}; // ""
        if (n == 1) return {s}; // "0", "1"
        if (s[0] == '0' && s[n - 1] == '0') return {}; // "0xxxx0"
        if (s[0] == '0') return {"0." + s.substr(1)}; // "0xxxx1"
        if (s[n - 1] == '0') return {s}; // "1xxx0"
        
        vector<string> res = {s};
        for (int i = 1; i < n; ++i)
            res.push_back(s.substr(0, i) + '.' + s.substr(i));
        return res;
    }
};
```
