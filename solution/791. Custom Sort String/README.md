# 791. Custom Sort String

## Solution 1: custom sort

### C++

```cpp
string customSortString(string order, string str) {
    vector<int> dict(128);
    for (int i = 0; i < order.size(); ++i)
        dict[order[i]] = i + 1;

    sort(str.begin(), str.end(), [&](char& a, char &b) {
        return dict[a] < dict[b];
    });
    return str;
}
```

or

```cpp
string customSortString(string order, string s) {
    vector<int> m(26, 27);
    for (int i = 0; i < order.size(); ++i)
        m[order[i] - 'a'] = i + 1;
    
    sort(s.begin(), s.end(), [m](char& a, char& b) {
        return m[a - 'a'] < m[b - 'a'];
    });
    return s;
}
```

### Python
```py
def customSortString(self, order: str, s: str) -> str:
    m = defaultdict(int)
    for i in range(len(order)):
        m[order[i]] = i + 1
    
    s = sorted(s, key=lambda c: m[c])
    return ''.join(s)
```

## Solution 2: counter

### C++
```cpp
string customSortString(string order, string str) {
    unordered_map<char, int> m;
    for (char& c : str)
        m[c]++;

    string ans;
    for (char& c : order) {
        ans += string(m[c], c);
        m[c] = 0;
    }

    for (auto& [c, count] : m)
        ans += string(count, c);

    return ans;
}
```

### Python
```py
def customSortString(self, order: str, s: str) -> str:
    m = defaultdict(int)
    for c in s:
        m[c] += 1
        
    res = ''
    for c in order:
        res += c * m[c]
        m[c] = 0
    
    for c, count in m.items():
        res += c * count
    
    return res

```
