# 1641. Count Sorted Vowel Strings

## Top-down (1641_01.cpp)

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
