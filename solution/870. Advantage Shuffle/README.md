# 870. Advantage Shuffle

## Solution 1 - map

用 upper_bound，盡量去找剛好能嬴的 num，

如果找不到，就用最小的 num 來輸掉這一回合。

```cpp
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    map<int, int> m;
    for (int a : A) ++m[a];

    vector<int> ans;
    for (int b : B) {
        auto it = m.upper_bound(b);
        it = it != m.end() ? it : m.begin();
        ans.push_back(it->first);
        if (--it->second == 0)
            m.erase(it);
    }

    return ans;
}
```

## Solution 2 - multiset

```cpp
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    multiset<int> s(begin(A), end(A));
    vector<int> ans;
    for (int b : B) {
        auto it = s.upper_bound(b);
        if (it == s.end()) it = s.begin();
        ans.push_back(*it);
        s.erase(it);
    }
    return ans;
}
```
