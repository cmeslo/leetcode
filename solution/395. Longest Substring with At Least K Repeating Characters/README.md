# 395. Longest Substring with At Least K Repeating Characters

## 解釋：

這是一個求解子字符串的問題，拆分成子問題處理，

先數一次整個字符串，26個字母的分別出現次數，

然後以不合格的字符，作為分割點，

```
[a,b,c,d,e,f,a,b,c,g,a,b,c,d], k = 2
         ^ ^       ^           e, f, g 都只出現了一次，所以不會是答案字符串的一部分

[o,o,o,o,x,x,o,o,o,x,o,o,o,o]
 ^-----^     ^---^   ^-----^   子問題變成求解這三個子字符串

[o,o,o,o,x,x,o,o,o,x,o,o,o,o]
 ^-----^     ^-------------^   更一般地說，拆分成兩個子問題求解
```

多個不合格字符相連的情況，用一個 while 循環避開，從合格的字符開始數，

好處是 避免了遞歸進去求解不合格字符，

不避開也可以，但後面要添加判斷：
```cpp
int len1 = i != 0 ? longestSubstring(s.substr(0, i), k) : 0;
int len2 = longestSubstring(s.substr(i == 0 ? 1 : i), k);
```
特登試了一下，這會變得非常慢，可能test case裡有很多這種情況，所以還是避開好。

## Code

Time complexity: O(N^2)

Your runtime beats 100.00 % of cpp submissions.

```cpp
int longestSubstring(string s, int k) {
    int n = s.length();
    if (n < k) return 0;
    if (k <= 1) return n;

    vector<int> f(26, 0);
    for (const char& c : s)
        ++f[c - 'a'];

    int l = 0;
    while (l < n && f[s[l] - 'a'] >= k) ++l;
    if (l >= n) return n;
    int len1 = longestSubstring(s.substr(0, l), k);

    while (l < n && f[s[l] - 'a'] < k) ++l;
    int len2 = longestSubstring(s.substr(l), k);

    return max(len1, len2);
}
```
