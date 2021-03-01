# 3. Longest Substring Without Repeating Characters

## c++ 代碼

### 用 set 作為 window

```cpp
int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int n = s.size();

    unordered_set<char> window;
    int l = 0, r = 0;
    while (l <= r && r < n) {
        while (window.count(s[r]))
            window.erase(s[l++]);
        window.insert(s[r]);
        ans = max(ans, r - l + 1);
        ++r;
    }
    return ans;
}
```

## java 代碼

```java
public int lengthOfLongestSubstring(String s) {
    if (s.length() == 0) return 0;

    int start = 0, max_len = 0;
    int[] map = new int[256];

    for (int i = 0; i < s.length(); ++i) {
        map[s.charAt(i)]++;
        while (map[s.charAt(i)] > 1) {
            map[s.charAt(start)]--;
            start++;
        }
        max_len = Math.max(max_len, i-start+1);
    }
    return max_len;
}
```
