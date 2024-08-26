# 791. Custom Sort String

## Solution 1: custom sort

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

## Solution 2: counter

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
