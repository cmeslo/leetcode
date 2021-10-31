# 2042. Check if Numbers Are Ascending in a Sentence

```cpp
bool areNumbersAscending(string s) {
    int pre = 0;
    istringstream ss(s);
    string str;
    while (ss >> str) {
        int i = 0;
        for (; i < str.size() && isdigit(str[i]); ++i);
        if (i == str.size()) {
            int cur = stoi(str);
            if (pre >= cur) return false;
            pre = cur;
        }
    }
    return true;
}
```
