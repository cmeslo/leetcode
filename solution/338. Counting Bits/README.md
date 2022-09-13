# 338. Counting Bits #

## 338_01.cpp

hints:
```
dp[0] = 0 = dp[0]
dp[1] = 1 = dp[1 - 1] + 1
dp[2] = 1 = dp[2 - 2] + 1
dp[3] = 2 = dp[3 - 2] + 1
dp[4] = 1 = dp[4 - 4] + 1
dp[5] = 2 = dp[5 - 4] + 1
dp[6] = 2 = dp[6 - 4] + 1
dp[7] = 3 = dp[7 - 4] + 1
dp[8] = 1 = dp[8 - 8] + 1
```

```cpp
vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    int offset = 1;
    for (int i = 1; i <= num; ++i) {
        if (offset << 1 == i) offset <<= 1;
        dp[i] = dp[i - offset] + 1;
    }
    return dp;
}
```

## 338_02.cpp
```
dp[i] = dp[i / 2] + i % 2;
```

```cpp
vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
        // dp[i] = dp[i / 2] + i % 2;
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}
```

## 338_03.cpp
找出規律如下表
1. 奇數 ```res[i]```：1 的數目是```res[i-1]+1```
2. 偶數 ```res[i]```：1 的數目是```res[i/2]```

```
i    binary  1的數目
0    0000      0
--------------------
1    0001      1 
--------------------
2    0010      1 
3    0011      2 
--------------------
4    0100      1 
5    0101      2 
6    0110      2 
7    0111      3 
--------------------
8    1000      1 
9    1001      2 
10   1010      2 
11   1011      3 
12   1100      2 
13   1101      3 
14   1110      3 
15   1111      4 
```

```cpp
// Runtime: 3 ms, Your runtime beats 97.31 % of cpp submissions.
// Memory Usage: 7.9 MB, Your memory usage beats 47.22 % of cpp submissions.

vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; ++i) {
        ans[i] = i % 2 ? ans[i - 1] + 1 : ans[i / 2];
    }
    return ans;
}
```
