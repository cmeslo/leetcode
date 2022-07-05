# 394. Decode String

## Solution 1: Recursion (394_01.cpp)

通過 recursive 獲得子字符串，

遞歸時參數 i 使用引用，跳過已處理的字符。

```cpp
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    
private:
    string decodeString(string& s, int& i) {
        string ans = "";
        
        while (i < s.length() && s[i] != ']') {
            if ('0' <= s[i] && s[i] <= '9') {
                int cnt = 0;
                while ('0' <= s[i] && s[i] <= '9')
                    cnt = cnt * 10 + s[i++] - '0';
                
                ++i; // skip '['
                string sub = decodeString(s, i);
                ++i; // skip ']'
                
                while (cnt--)
                    ans += sub;
            } else {
                ans += s[i++];
            }
        }
        
        return ans;
    }
};
```

## Solution 2: Recursion (394_02.cpp)

另一種寫法

```cpp
class Solution {
public:
    string decodeString(string s) {
        unordered_map<int, int> next;
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[')
                st.push(i);
            else if (s[i] == ']') {
                next[st.top()] = i;
                st.pop();
            }
        }
        return dfs(s, 0, s.size() - 1, next);
    }
    
private:
    string dfs(string& s, int l, int r, unordered_map<int, int>& next) {
        if (l > r) return "";
        string res;
        if (isalpha(s[l])) {
            while (l <= r && isalpha(s[l])) {
                res += s[l++];
            }
            return res + dfs(s, l, r, next);
        } else if ('0' <= s[l] && s[l] <= '9') {
            int cnt = 0;
            while (l < r && '0' <= s[l] && s[l] <= '9') {
                cnt = cnt * 10 + (s[l++] - '0');
            }
            string w = dfs(s, l + 1, next[l] - 1, next);
            for (int i = 0; i < cnt; ++i)
                res += w;
            return res + dfs(s, next[l] + 1, r, next);
        }
        return "";
            
    }
};
```
