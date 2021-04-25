# 13. Roman to Integer

比較差的做法：

```cpp
int romanToInt(string s) {
    unordered_map<string, int> m = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };

    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && m[s.substr(i, 1)] < m[s.substr(i + 1, 1)])
            ans += m[s.substr(i++, 2)];
        else
            ans += m[s.substr(i, 1)];
    }
    return ans;
}
```

## Solution

### 解釋

先觀察一下羅馬數字中那些兩個字符的特殊情況，如果是正常累加時：

```py
IV = 1 + 5 = 6 （但正確答案應該是 4）
XL = 10 + 50 = 60 （但正確答案應該是 40）
...
CM = 100 + 1000 = 1100 （但正確答案應該是 900）
```

發現每次都會多走了兩"步"，

所以規律就是：減去 2 倍的第一位數字

```py
IV = 1 + 5 - 2*1 = 4
XL = 10 + 50 - 2*10 = 40
...
CM = 100 + 1000 - 2*100 = 900
```

### Code

```cpp
int romanToInt(string s) {
    unordered_map<char, int> m {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans += m[s[i]];
        // 正常羅馬數字、左至右是從大至小的；當出現從小至大時，代表遇到兩個字符的特殊情況。
        if (i > 0 && m[s[i - 1]] < m[s[i]])
            ans -= 2 * m[s[i - 1]];
    }
    return ans;
}
```
