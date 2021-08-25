# 1967. Number of Strings That Appear as Substrings in Word

```cpp
int numOfStrings(vector<string>& patterns, string word) {
    int ans = 0;
    for (string& s : patterns) {
        auto it = word.find(s);
        if (it != string::npos)
            ++ans;
    }
    return ans;
}
```
