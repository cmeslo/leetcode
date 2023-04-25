# 2131. Longest Palindrome by Concatenating Two Letter Words

## Solution 1: hashmap

```cpp
int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> m;
    for (string& w : words) m[w]++;

    bool middle = false;
    int res = 0;
    for (auto& [w, cnt] : m) {
        if (cnt == 0) continue;
        if (w[0] == w[1]) {
            if (cnt % 2) {
                if (!middle) {
                    middle = true;
                    res += 2;
                }
                cnt--;
            }
            res += cnt * 2;
            cnt = 0;
        } else {
            string mirror = w;
            reverse(mirror.begin(), mirror.end());
            if (m.count(mirror)) {
                res += min(cnt, m[mirror]) * 4;
                cnt = m[mirror] = 0;
            }
        }
    }
    return res;
}
```

## Solution 2: 更簡潔的寫法

```cpp
int longestPalindrome(vector<string>& words) {
    int n = words.size();
    int ans = 0;
    vector<vector<int>> m(26, vector<int>(26));
    for (string& w : words) {
        int a = w[0] - 'a', b = w[1] - 'a';
        if (m[b][a]) {
            ans += 4;
            m[b][a]--;
        } else {
            m[a][b]++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (m[i][i]) {
            ans += 2;
            break;
        }
    }
    return ans;
}
```
