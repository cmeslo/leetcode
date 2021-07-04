# 1209. Remove All Adjacent Duplicates in String II

## Solution1: Stack

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
