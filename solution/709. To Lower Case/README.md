# 709. To Lower Case

```cpp
string toLowerCase(string s) {
    for (char& c : s)
        if ('A' <= c && c <= 'Z')
            c += 32;
    return s;
}
```
