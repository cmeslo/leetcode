# 443. String Compression

## Solution: Two Pointers

```O(n)``` space

```cpp
int compress(vector<char>& chars) {
    vector<pair<char, int>> A;
    A.push_back({chars[0], 0});
    for (char& c : chars) {
        if (A.back().first == c)
            A.back().second++;
        else
            A.push_back({c, 1});
    }
    int i = 0;
    for (int j = 0; j < A.size(); ++j) {
        chars[i++] = A[j].first;
        if (A[j].second == 1) continue;
        string num = to_string(A[j].second);
        for (char& c : num)
            chars[i++] = c;
    }
    return i;
}
```
or

in-place 的方法

```cpp
int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0;
    for (int j = 1, len = 1; j <= n; ++j, ++len) {
        if (j == n || chars[j] != chars[j - 1]) {
            chars[i++] = chars[j - 1];
            if (len > 1) {
                string num = to_string(len);
                for (char& x : num)
                    chars[i++] = x;
            }
            len = 0;
        }
    }
    return i;
}
```
