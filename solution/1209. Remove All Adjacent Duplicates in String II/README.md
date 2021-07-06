# 1209. Remove All Adjacent Duplicates in String II

## Solution 1: Stack

```cpp
string removeDuplicates(string s, int k) {
    vector<pair<int, char>> st = {{0, '#'}};

    for (char c : s) {
        if (st.back().second != c)
            st.push_back({1, c});
        else if (++st.back().first == k)
            st.pop_back();
    }

    string ans;
    for (auto& [cnt, c] : st)
        ans.append(cnt, c);
    return ans;
}
```

## Solution 2: Two Pointers

```cpp
string removeDuplicates(string s, int k) {
    int n = s.length();
    int i = 0;
    vector<int> count(n);
    for (int j = 0; j < n; ++j, ++i) {
        s[i] = s[j];
        count[i] = i > 0 && s[i - 1] == s[j] ? count[i - 1] + 1 : 1;
        if (count[i] == k)
            i -= k;
    }
    return s.substr(0, i);
}
```
