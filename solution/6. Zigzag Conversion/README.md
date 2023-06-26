# 6. Zigzag Conversion

## Solution

```cpp
string convert(string s, int n) {
    if (n == 1) return s;
    
    vector<string> A(n);
    int dir = 0; // 0 - down, 1 - up
    int index = 0;
    for (char& c : s) {
        A[index] += c;
        if (dir == 0) {
            if (++index == n) {
                dir = 1;
                index = n - 2;
            }
        } else {
            if (--index == -1) {
                dir = 0;
                index = 1;
            }
        }
    }
    
    string res;
    for (const string& row : A)
        res.append(row);
    return res;
}
```

or

```cpp
string convert(string s, int n) {
    vector<string> A(n);
    for (int i = 0; i < s.size();) {
        for (int j = 0; j < n && i < s.size(); ++j, ++i)
            A[j].push_back(s[i]);
        for (int j = n - 2; j >= 1 && i < s.size(); --j, ++i)
            A[j].push_back(s[i]);
    }
    
    string res;
    for (const string& row : A)
        res.append(row);
    return res;
}
```
