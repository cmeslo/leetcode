# 38. Count and Say

## Solution 1

```cpp
// Runtime: 4 ms, Your runtime beats 85.62 % of cpp submissions.
// Memory Usage: 6.5 MB, Your memory usage beats 92.11 % of cpp submissions.

string countAndSay(int n) {
    queue<char> q;
    q.push('1');
    while (--n) {
        char pre = q.front(); q.pop();
        int len = 1;
        int size = q.size();
        while (size--) {
            char c = q.front(); q.pop();
            if (pre == c) {
                ++len;
            } else {
                for (char t : to_string(len))  q.push(t);
                q.push(pre);
                pre = c;
                len = 1;
            }
        }
        for (char t : to_string(len)) q.push(t);
        q.push(pre);
    }

    string res = "";
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}
```

## Solution 2

```cpp
// Runtime: 18 ms, Your runtime beats 22.96 % of cpp submissions.
// Memory Usage: 6.7 MB, Your memory usage beats 60.83 % of cpp submissions.

string countAndSay(int n) {
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); ++i) {
            int count = 1;
            while (i + 1 < res.size() && res[i] == res[i + 1]) {
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
```
