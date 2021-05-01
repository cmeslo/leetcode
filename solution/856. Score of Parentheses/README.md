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

## Solution 2: Iterative

### 解釋

累加左括號記錄到變量 ```d```，把 ```d``` 初始化成 -1，

遇到左括號 +1、遇到右括號 -1，

當遇到 ```()``` 時，答案加上 ```1 << d```。

#### 例子1

```
(())()
^-------d = 0
(())()
 ^------d = 1，發現 i+1 是 ')'，所以 ans += (1 << 1)，ans = 2
(())()
  ^-----d = 0
(())()
   ^----d = -1
(())()
    ^---d = 0，發現 i+1 是 ')'，所以 ans += (1 << 0), ans = 3
(())()
     ^--d = -1

最後 ans = 3
```

#### 例子2
```
(()())
^-------d = 0
(()())
 ^------d = 1，發現 i+1 是 ')'，所以 ans += (1 << 1)，ans = 2
(()())
  ^-----d = 0
(()())
   ^----d = 1，發現 i+1 是 ')'，所以 ans += (1 << 1)，ans = 4
(()())
    ^---d = 0
(()())
     ^--d = -1

最後 ans = 4
```
這裡相當於 ```(a + b) * 2 = a * 2 + b * 2```

### Code

```cpp
int scoreOfParentheses(string S) {
    int ans = 0;
    int d = -1;

    for (int i = 0; i < S.size(); ++i) {
        d += (S[i] == '(' ? 1 : -1);
        if (S[i] == '(' && S[i + 1] == ')')
            ans += 1 << d;
    }
    return ans;
}
```
