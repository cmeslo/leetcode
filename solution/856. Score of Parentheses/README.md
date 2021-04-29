# 856. Score of Parentheses

## Solution 1: recursive

### 解釋
分別遞歸計算每一組平衡的括號。

### Code
```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size() - 1);
    }
    
private:
    int score(string& s, int l, int r) {
        if (l + 1 == r) return 1;
        int cnt = 0;
        for (int i = l; i < r; ++i) { // 注意這裡走到 r - 1 就可以了，因為如果走到 r - 1 都未平衡，代表當前字符串的外層有一組括號
            if (s[i] == '(')
                ++cnt;
            else
                --cnt;
            if (cnt == 0)
                return score(s, l, i) + score(s, i + 1, r);
        }
        return 2 * score(s, l + 1, r - 1);
    }
};
```
