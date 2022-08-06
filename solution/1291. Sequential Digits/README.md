# 1291. Sequential Digits

## 1291_02.cpp (推薦)

```cpp
vector<int> sequentialDigits(int low, int high) {
    queue<int> q;
    for (int i = 1; i < 10; ++i)
        q.push(i);

    vector<int> ans;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (high < cur) break;

        if (low <= cur)
            ans.push_back(cur);

        int last = cur % 10;
        if (last < 9)
            q.push(cur * 10 + (last + 1));
    }

    return ans;
}
```

## 1291_03.cpp

```cpp
vector<int> sequentialDigits(int low, int high) {
    int mn_len = to_string(low).size();
    int mx_len = to_string(high).size();
    vector<int> res;
    for (int len = mn_len; len <= mx_len; ++len) {
        int cur = 0;
        for (int i = 1; i <= len; ++i) {
            cur = cur * 10 + i;
        }
        while (to_string(cur).size() <= len && cur <= high) {
            if (low <= cur && cur <= high)
                res.push_back(cur);
            int r = cur % 10;
            if (r == 9) break;
            cur = cur % (int)pow(10, len - 1) * 10 + r + 1;
        }
    }
    return res;
}
```
