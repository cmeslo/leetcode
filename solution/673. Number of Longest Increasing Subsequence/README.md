# 673. Number of Longest Increasing Subsequence

## 673_01.cpp

```cpp
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), max_len = 1, res = 0;
    vector<int> len(n, 1);
    vector<int> cnt(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }

        if (max_len < len[i]) {
            max_len = len[i];
            res = cnt[i];
        } else if (max_len == len[i]) {
            res += cnt[i];
        }
    }

    return res;
}
```

## 673_02.cpp

```cpp
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> len(n, 1);
    vector<int> cnt(n, 1);

    for (int i = 1; i < n; ++i) {
        len[i] = cnt[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
    }

    int ans = 0;
    int max_len = *max_element(len.begin(), len.end());
    for (int i = 0; i < n; ++i)
        if (len[i] == max_len)
            ans += cnt[i];

    return ans;
}
```

## 同樣的算法，把 vector 換成 array，可以提速

Your runtime beats 94.13 % of cpp submissions.

```cpp
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), max_len = 1, ans = 0;
    if (n == 0) return 0;

    int len[n];
    int cnt[n];

    for (int i = 0; i < n; ++i) {
        len[i] = cnt[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }

        if (max_len < len[i]) {
            max_len = len[i];
            ans = cnt[i];
        } else if (max_len == len[i]) {
            ans += cnt[i];
        }
    }

    return ans;
}
```

```cpp
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), max_len = 1, ans = 0;
    if (n == 0) return 0;
    if (n == 1) return 1;

    int len[n];
    int cnt[n];

    for (int i = 0; i < n; ++i) {
        len[i] = cnt[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        max_len = max(max_len, len[i]);
    }

    for (int i = 0; i < n; ++i)
        if (len[i] == max_len)
            ans += cnt[i];

    return ans;
}
```
