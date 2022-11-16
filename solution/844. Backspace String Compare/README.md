# 844. Backspace String Compare

```cpp
bool backspaceCompare(string s, string t) {
    string ss, tt;
    for (char& c : s) {
        if (c == '#') {
            if (!ss.empty())
                ss.pop_back();
        } else {
            ss.push_back(c);
        }
    }
    for (char& c : t) {
        if (c == '#') {
            if (!tt.empty())
                tt.pop_back();
        } else {
            tt.push_back(c);
        }
    }
    return ss == tt;
}
```
