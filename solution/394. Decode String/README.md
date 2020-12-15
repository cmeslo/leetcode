# 394. Decode String

## 394_01.cpp

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
