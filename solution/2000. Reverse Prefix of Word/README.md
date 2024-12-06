# 2000. Reverse Prefix of Word

```cpp
string reversePrefix(string word, char ch) {
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == ch) {
            reverse(word.begin(), word.begin() + i + 1);
            break;
        }
    }
    return word;
}
```

or

```cpp
string reversePrefix(string word, char ch) {
    for (int i = 0, j = 0; j < word.size(); ++j) {
        if (word[j] == ch) {
            while (i < j) {
                swap(word[i++], word[j--]);
            }
            break;
        }
    }
    return word;
}
```
