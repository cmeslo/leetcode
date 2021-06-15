# 423. Reconstruct Original Digits from English

## 會TLE的解法

```cpp
string originalDigits(string s) {
    vector<int> f(26);

    for (char c : s)
        ++f[c - 'a'];

    string ans;
    int cnt = s.size();
    while (cnt) {
        if (f[25] && f[4] && f[17] && f[14]) {
            f[25]--;
            f[4]--;
            f[17]--;
            f[14]--;
            ans += '0';
            cnt -= 4;
        }
        if (f[14] && f[13] && f[4]) {
            f[14]--;
            f[13]--;
            f[4]--;
            ans += '1';
            cnt -= 3;
        }
        if (f[19] && f[22] && f[14]) {
            f[19]--;
            f[22]--;
            f[14]--;
            ans += '2';
            cnt -= 3;
        }
        if (f[19] && f[7] && f[17] && f[4] > 1) {
            f[19]--;
            f[7]--;
            f[17]--;
            f[4] -= 2;
            ans += '3';
            cnt -= 5;
        }
        if (f[5] && f[14] && f[20] && f[17]) {
            f[5]--;
            f[14]--;
            f[20]--;
            f[17]--;
            ans += '4';
            cnt -= 4;
        }
        if (f[5] && f[8] && f[21] && f[4]) {
            f[5]--;
            f[8]--;
            f[21]--;
            f[4]--;
            ans += '5';
            cnt -= 4;
        }
        if (f[18] && f[8] && f[23]) {
            f[18]--;
            f[8]--;
            f[23]--;
            ans += '6';
            cnt -= 3;
        }
        if (f[18] && f[4] > 1 && f[21] && f[13]) {
            f[18]--;
            f[4] -= 2;
            f[21]--;
            f[13]--;
            ans += '7';
            cnt -= 5;
        }
        if (f[4] && f[8] && f[6] && f[7] && f[19]) {
            f[4]--;
            f[8]--;
            f[6]--;
            f[7]--;
            f[19]--;
            ans += '8';
            cnt -= 5;
        }
        if (f[13] > 1 && f[8] && f[4]) {
            f[13] -= 2;
            f[8]--;
            f[4]--;
            ans += '9';
            cnt -= 4;
        }
    }
    sort(begin(ans), end(ans));
    return ans;
}
```

## Solution - 找規律

### 解釋

英文的 0 - 9 裡，0,2,4,6,8 是可以通過某個字母唯一標識的，1,3,5,7,9 不能；

比如每次出現字母 i ，我都先計入nine裡，最後自己減去多餘的部分：

```
zero
one
two
three
four
f[i]ve
s[i]x
seven
e[i]ght
n[i]ne, count[9] = count[9] - count[8] - count[6] - count[5]
```

### Code
```cpp
string originalDigits(string s) {
    vector<int> count(10);
    for (char c : s) {
        if (c == 'z') ++count[0];
        if (c == 'w') ++count[2];
        if (c == 'u') ++count[4];
        if (c == 'x') ++count[6];
        if (c == 'g') ++count[8];
        if (c == 'o') ++count[1]; // 1 - 0 - 2 - 4
        if (c == 't') ++count[3]; // 3 - 2 - 8
        if (c == 'f') ++count[5]; // 5 - 4
        if (c == 's') ++count[7]; // 7 - 6
        if (c == 'i') ++count[9]; // 9 - 8 - 6 - 5
    }

    count[1] = count[1] - count[0] - count[2] - count[4];
    count[3] = count[3] - count[2] - count[8];
    count[5] = count[5] - count[4];
    count[7] = count[7] - count[6];
    count[9] = count[9] - count[8] - count[6] - count[5];

    string ans;
    for (int i = 0; i < 10; ++i)
        ans += string(count[i], '0' + i);
    return ans;
}
```
