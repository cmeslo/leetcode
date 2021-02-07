# 880. Decoded String at Index

## 880_01.cpp

不斷計算最新的字符串長度，如果超過了再倒退回來

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
