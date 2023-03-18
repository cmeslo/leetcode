# 557. Reverse Words in a String III

```cpp
string reverseWords(string s) {
    string res;
    istringstream iss(s);
    string word;
    while (iss >> word) {
        int i = 0, j = word.size() - 1;
        while (i < j)
            swap(word[i++], word[j--]);
        res += ' ' + word;
    }
    return res.substr(1);
}
```

or

```cpp
string reverseWords(string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        while (r < n && s[r] != ' ') ++r;
        i = r;
        --r;
        while (l < r)
            swap(s[l++], s[r--]);
    }
    return s;
}
```

or

```cpp
string reverseWords(string s) {
    int n = s.size();
    int front = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] == ' ') {
            // reverse(s.begin() + front, s.begin() + i);
            reverse(&s[front], &s[i]);
            front = i + 1;
        }
    }
    return s;
}
```
