# 1897. Redistribute Characters to Make All Strings Equal

## Solution: HashMap

### C++

```cpp
bool makeEqual(vector<string>& words) {
    const int n = words.size();
    
    vector<int> f(26);
    for (string& word : words)
        for (char& c : word)
            ++f[c - 'a'];
    
    for (int i = 0; i < 26; ++i)
        if (f[i] % n)
            return false;
    
    return true;
}
```

or

```cpp
bool makeEqual(vector<string>& words) {
    const int n = words.size();
    
    vector<int> f(26);
    for (string& word : words)
        for (char& c : word)
            ++f[c - 'a'];
    
    return all_of(begin(f), end(f), [&](int c) { return c % n == 0; });
}
```

### Python

```py
def makeEqual(self, words: List[str]) -> bool:
    joint = ''.join(words)
    s = set(joint)
    
    for i in s:
        if joint.count(i) % len(words) != 0: return False
    return True
```
