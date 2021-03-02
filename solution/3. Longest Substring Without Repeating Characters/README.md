# 3. Longest Substring Without Repeating Characters

## c++ 代碼

### 用 set 作為 window (3_01.cpp)

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

### 用 array 作為 map (3_02.cpp)

```cpp
int lengthOfLongestSubstring(string s) {
    int ans = 0;

    vector<int> seen(256);
    int start = 0;
    for (int i = 0; i < s.length(); ++i) {
        while (seen[s[i]] > 0) {
            --seen[s[start++]];
        }
        ++seen[s[i]];
        ans = max(ans, i - start + 1);
    }
    return ans;
}
```

or

```cpp
int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int n = s.size();

    vector<int> window(256);
    int l = 0, r = 0;
    while (l <= r && r < n) {
        ++window[s[r]];
        while (window[s[r]] > 1)
            --window[s[l++]];
        ans = max(ans, r - l + 1);
        ++r;
    }
    return ans;
}
```

## java 代碼

### 用 array 作為 map (3_01.java)

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
