# 752. Open the Lock

## Solution 1: BFS

```cpp
// Your runtime beats 52.46 % of cpp submissions.
// Your memory usage beats 45.16 % of cpp submissions.

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends));
        
        int level = 0;
        queue<string> q;
        dead.insert(target);
        q.push(target);
        
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                string cur = q.front(); q.pop();
                if (cur == "0000") return level;
                getNext(cur, q, dead);
            }
            ++level;
        }
        return -1;
    }
    
private:
    void getNext(string cur, queue<string>& q, unordered_set<string>& dead) {
        for (int i = 0; i < 4; ++i) {
            // +1
            string next = cur;
            next[i] = cur[i] == '9' ? '0' : cur[i] + 1;
            if (!dead.count(next)) {
                dead.insert(next);
                q.push(next);
            }
            // -1
            next[i] = cur[i] == '0' ? '9' : cur[i] - 1;
            if (!dead.count(next)) {
                dead.insert(next);
                q.push(next);
            }
        }
    }
};
```

## Solution 2: Bidirectional BFS

```cpp
// Your runtime beats 96.38 % of cpp submissions.
// Your memory usage beats 96.51 % of cpp submissions.

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> q1, q2;
    unordered_set<string> dead(begin(deadends), end(deadends)); // visited

    string init = "0000";
    if (dead.count(init) || dead.count(target)) return -1;
    if (init == target) return 0;
    dead.insert(init);
    dead.insert(target);
    q1.insert(init);
    q2.insert(target);

    int level = 0;
    while (!q1.empty() && !q2.empty()) {
        if (q1.size() > q2.size())
            swap(q1, q2);

        unordered_set<string> q;
        for (const string& cur : q1) {
            for (int i = 0; i < 4; ++i) {
                string next = cur;
                for (int j = -1; j <= 1; j += 2) {
                    next[i] = (cur[i] - '0' + j + 10) % 10 + '0';
                    if (q2.count(next)) return level + 1;
                    if (dead.count(next)) continue;
                    dead.insert(next);
                    q.insert(next);
                }
            }
        }
        swap(q1, q);
        ++level;
    }
    return -1;
}
```
