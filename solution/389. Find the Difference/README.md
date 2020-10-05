# 389. Find the Difference

## XOR

wrong way:

```cpp
char findTheDifference(string s, string t) {
    char ans = 0;
    for (char c : s) ans ^= c;
    for (char c : t) ans ^= c;
    return ans;
}
```

right work:

```cpp
char findTheDifference(string s, string t) {
    int ans = 0;
    for (char c : s) ans ^= (c - 'a');
    for (char c : t) ans ^= (c - 'a');
    return ans + 'a';

}
```

## vector

### 389_03.cpp
```cpp
char findTheDifference(string s, string t) {
    vector<int> letters(26, 0);

    for (int i = 0; i < s.length(); ++i)
        ++letters[s[i] - 'a'];

    for (int i = 0; i < t.length(); ++i)
        --letters[t[i] - 'a'];

    for (int i = 0; i < letters.size(); ++i)
        if (letters[i] != 0) return i + 'a';

    return '\0';
}
```

### 389_04.cpp
```cpp
char findTheDifference(string s, string t) {
    vector<int> letters(26, 0);

    for (int i = 0; i < s.length(); ++i) {
        ++letters[s[i] - 'a'];
        --letters[t[i] - 'a'];
    }
    --letters[t.back() - 'a'];

    for (int i = 0; i < letters.size(); ++i)
        if (letters[i] != 0) return i + 'a';

    return '\0';
}
```
