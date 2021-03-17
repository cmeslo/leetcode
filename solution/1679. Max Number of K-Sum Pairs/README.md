# 1679. Max Number of K-Sum Pairs

## map (1679_01.cpp)

Time complexity: ```O(n)```

### 較好的寫法：
```cpp
// Your runtime beats 99.18 % of cpp submissions.

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int n : nums)
        if (n < k) ++m[n];

    int ans = 0;
    for (auto& [x, cnt] : m) {
        if (m.find(k - x) == m.end()) continue;
        if (k - x == x) {
            // if (cnt == 1) continue; // 沒有這行也可以
            ans += cnt / 2;
            // cnt = cnt % 2 ? 1 : 0; // 沒有這行也可以
        } else {
            int pairs = min(cnt, m[k - x]);
            m[k - x] -= pairs;
            cnt -= pairs;
            ans += pairs;
        }
    }

    return ans;
}
```

or

### 普通的寫法：

```cpp
// Your runtime beats 61.27 % of cpp submissions.

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int x : nums)
        ++m[x];

    int ans = 0;
    for (int x : nums) {
        if (x == k - x) {
            if (m[x] > 1) {
                m[x] -= 2;
                ++ans;
            }
        } else if (m[x] > 0 && m.count(k - x) && m[k - x] > 0) {
            --m[x];
            --m[k - x];
            ++ans;
        }
    }
    return ans;
}
```
