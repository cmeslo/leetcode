# 2131. Longest Palindrome by Concatenating Two Letter Words

## Solution 1: hashmap

```cpp
int longestPalindrome(vector<string>& words) {
    int res = 0;
    unordered_map<string, int> m;
    bool middle = false;

    for (string& w : words) {
        m[w]++;
    }

    for (auto& [w, cnt] : m) {
        if (w[0] == w[1]) {
            if (cnt % 2 == 0)
                res += cnt * 2;
            else {
                res += (cnt - 1) * 2;
                if (!middle) {
                    middle = true;
                    res += 2;
                }
            }
        } else {
            if (cnt <= 0) continue;
            string mirror = w.substr(1, 1) + w.substr(0, 1);
            if (m.count(mirror) && m[mirror] > 0) {
                int mn = min(cnt, m[mirror]);
                res += mn * 4;
                cnt -= mn;
                m[mirror] -= mn;
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
