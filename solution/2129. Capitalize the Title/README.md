# 2129. Capitalize the Title

```cpp
string capitalizeTitle(string title) {
    string res;
    stringstream ss(title);
    string cur;
    while (ss >> cur) {
        if (cur.size() <= 2) {
            for (char& c : cur)
                c = tolower(c);
        } else {
            cur[0] = toupper(cur[0]);
            for (int i = 1; i < cur.size(); ++i)
                cur[i] = tolower(cur[i]);
        }
        res += !res.empty() ? " " + cur : cur;
    }
    return res;
}
```
