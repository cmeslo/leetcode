# 752. Open the Lock

## Solution 1: BFS

```cpp
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
