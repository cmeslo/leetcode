# 1773. Count Items Matching a Rule

## 浪費空間的做法：

```cpp
int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    unordered_map<string, int> m0;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;

    for (auto& item : items) {
        ++m0[item[0]];
        ++m1[item[1]];
        ++m2[item[2]];
    }

    if (ruleKey == "type")
        return m0.count(ruleValue) ? m0[ruleValue] : 0;
    if (ruleKey == "color")
        return m1.count(ruleValue) ? m1[ruleValue] : 0;
    if (ruleKey == "name")
        return m2.count(ruleValue) ? m2[ruleValue] : 0;
    return 0;
}
```

## 優化：

```cpp
int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int ans = 0;
    for (auto& item : items) {
        if ((ruleKey == "type" && item[0] == ruleValue)
            || (ruleKey == "color" && item[1] == ruleValue)
            || (ruleKey == "name" && item[2] == ruleValue))
            ++ans;
    }
    return ans;
}
```
