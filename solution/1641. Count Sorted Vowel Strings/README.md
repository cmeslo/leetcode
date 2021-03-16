# 1641. Count Sorted Vowel Strings

## Solution 1: Top-down (1641_01.cpp)

### 解釋：

```py
a
e
i
o
u
^-----------第一個選擇

a {a,e,i,o,u}
e {e,i,o,u}
i {i,o,u}
o {o,u}
u {u}
   ^---------限制了第二個選擇

dp(n, 5);
      ^-----剩餘可選擇數目
```

```py
Base case:
dp(1, x);
   ^-------剩下 1 個位置，和 x 個侯選字母，返回 x
dp(x, 1);
      ^----剩 1 個侯選字母，返回 1
```

### Code

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        return dp(n, 5);
    }
    
private:
    int dp(int n, int remain) {
        if (n == 1 || remain == 1) return remain;
        
        int ans = 0;
        for (int i = remain; i >= 1; --i)
            ans += dp(n - 1, i);
        return ans;
    };
};
```

### 加上記憶化：

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> mem(n + 1, vector<int>(6));
        return dp(n, 5, mem);
    }
    
private:
    int dp(int n, int remain, vector<vector<int>>& mem) {
        if (n == 1 || remain == 1) return remain;
        if (mem[n][remain]) return mem[n][remain];
        
        int ans = 0;
        for (int i = remain; i >= 1; --i)
            ans += dp(n - 1, i, mem);
        return mem[n][remain] = ans;
    };
};
```

## Solution 2: Bottom-up DP (1641_02.cpp)

畫表：

| n\k | u | o | i  | e  | a  |
|-----|---|---|----|----|----|
| 1   | 1 | 1 | 1  | 1  | 1  |
| 2   | 1 | 2 | 3  | 4  | 5  |
| 3   | 1 | 3 | 6  | 10 | 15 |
| 4   | 1 | 4 | 10 | 20 | 35 |

### Code:

```cpp
int countVowelStrings(int n) {
  vector<int> dp = {0, 1, 1, 1, 1, 1};

  for (int i = 1; i < n; ++i)
      for (int j = 1; j <= 5; ++j)
          dp[j] += dp[j - 1];

  return accumulate(begin(dp), end(dp), 0);
}
```

or

```cpp
int countVowelStrings(int n) {
  vector<int> dp = {0, 1, 1, 1, 1, 1};

  for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= 5; ++j)
          dp[j] += dp[j - 1];

  return dp[5];
}
```

## Solution 3: math (1641_03.cpp)

### 檔板

向 n 個位置插入 4 個檔板 l

```
在第一個 l 前面，放 a，有 n + 1 種插法
在第二個 l 前面，放 e，有 n + 2 種插法
在第三個 l 前面，放 i，有 n + 3 種插法
在第四個 l 前面，放 o，有 n + 4 種插法
在第四個 l 後面，放 u
```

比如 n = 5：
```
a a e e i 代表
a a | e e | i ||

a a a a a 代表
a a a a a | | | |

u u u u u 代表
| | | | u u u u u
```

理解思路一：
```
有 (n + 1) * (n + 2) * (n + 3) * (n + 4) 種插法，

當中 4 塊檔板的位置沒有順序關係，所以再除以 4! = 24

所以答案就是 (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24
```

理解思路二：
```
也可以理解成 從 n + 4 個位置中，找 4 個位置放入檔板 l

組合公式
C(n + 4, 4)
= (n + 4) * (n + 3) * (n + 2) * (n + 1) * n! / ((n + 4 - 4)! * 4!)
= (n + 4) * (n + 3) * (n + 2) * (n + 1) * n! / (n! * 4!)
= (n + 4) * (n + 3) * (n + 2) * (n + 1) / 4!
```

### Code:

```cpp
int countVowelStrings(int n) {
  return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
}
```
