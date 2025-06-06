# 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

## Solution: Union Find

```cpp
class UFS {
public:
    vector<int> father;
    int count;
    
    UFS(int n): father(n), count(n) {
        for (int i = 0; i < n; ++i)
            father[i] = i;
    }
    
    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
        count--;
    }
    
    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UFS alice(n), bob(n);
        
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[0] > b[0];
        });
        
        int usedCount = 0;
        for (auto& e : edges) {
            bool used = false;
            int type = e[0], a = e[1] - 1, b = e[2] - 1;
            if (type == 1 || type == 3) {
                if (alice.findFather(a) != alice.findFather(b)) {
                    alice.merge(a, b);
                    used = true;
                }
            }
            if (type == 2 || type == 3) {
                if (bob.findFather(a) != bob.findFather(b)) {
                    bob.merge(a, b);
                    used = true;
                }
            }
            usedCount += used;
        }
        return alice.count == 1 && bob.count == 1 ? edges.size() - usedCount : -1;
    }
};
```
