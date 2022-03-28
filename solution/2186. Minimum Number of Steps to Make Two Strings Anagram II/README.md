# 2186. Minimum Number of Steps to Make Two Strings Anagram II

```cpp
int minSteps(string s, string t) {
    vector<int> m1(26), m2(26);
    for (char& c : s)
        m1[c - 'a']++;
    for (char& c : t)
        m2[c - 'a']++;

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += max(m1[i], m2[i]) - min(m1[i], m2[i]);
    }
    return ans;
}
```
