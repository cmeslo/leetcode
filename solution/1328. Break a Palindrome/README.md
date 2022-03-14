# 1328. Break a Palindrome

## 解釋

- case 1: 字符串長度 = 1，返回 empty

- case 2: 只要檢查到 n / 2 之前，如果不是 'a' 就換成 'a'
```
[x] x x

x [x] x x
```

- case 3: 如果除了中間以外、全部都是 'a'，就把最後一個字母換成 'b'
```
a b a <--奇數長度，換中間也仍然是 Palindrome
a b b

a a a a
a a a b
```



## Code

```cpp
string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    if (n == 1) return "";

    for (int i = 0; i < n / 2; ++i) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome.back() = 'b';
    return palindrome;
}
```
