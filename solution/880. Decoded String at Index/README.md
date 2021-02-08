# 880. Decoded String at Index

## 880_01.cpp

不斷計算最新的字符串長度，如果超過了再倒退回來

只要注意一個特殊情況，k是延伸後的最後一個字符，例如 ```s = "abcd2", k = 8``` 或 ```s = "ab22", k = 4```

```cpp
string decodeAtIndex(string S, int K) {
    int n = S.size();
    int i;
    long cnt = 0;
    for (i = 0; i < n && cnt < K; ++i) {
        if (isdigit(S[i]))
            cnt *= S[i] - '0';
        else
            ++cnt;
    }

    while (i--) {
        if (isdigit(S[i])) {
            cnt /= S[i] - '0';
            K %= cnt;
        } else {
            if (K == cnt || K == 0)
                return string(1, S[i]);
            --cnt;
            // 也可以這樣寫：
            // if (K % cnt == 0)
            //     return string(1, S[i]);
            // --cnt;
        }
    }

    return "";
}
```

## 880_02.cpp (Recursive)

```cpp
string decodeAtIndex(string S, int K) {
    int n = S.size();
    long cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(S[i])) {
            int times = S[i] - '0';
            if (cnt * times < K) {
                // 相乘後仍然小於 K，可以繼續
                cnt *= times;
            } else if (K % cnt == 0) {
                // 相乘後大於等於 K，並且 K 是 cnt 的數倍 -> 代表答案是當前 cnt 裡的的最後一個字符
                return decodeAtIndex(S.substr(0, i), cnt);
            } else {
                // 相乘後大於等於 K，並且 K 不是 cnt 的數倍 -> 代表相乘後，K 超出了一點點，
                // 在當前 cnt 上，尋找相應縮小的第 K 個字符，把 K % cnt
                return decodeAtIndex(S.substr(0, i), K % cnt);
            }
        } else {
            ++cnt;
            if (K == cnt || K == 0)
                return string(1, S[i]);
        }
    }
    return "";
}
```
