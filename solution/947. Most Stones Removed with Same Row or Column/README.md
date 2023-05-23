# 947. Most Stones Removed with Same Row or Column

## Solution: Union Find

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> rows, cols;
        for (int i = 0; i < n; ++i) {
            int y = stones[i][0], x = stones[i][1];
            rows[y].push_back(i);
            cols[x].push_back(i);
            father[i] = i;
        }
        
        for (auto& [y, arr] : rows) {
            for (int i : arr) {
                merge(rows[y][0], i);
            }
        }
        for (auto& [x, arr] : cols) {
            for (int i : arr) {
                merge(cols[x][0], i);
            }
        }
        
        unordered_set<int> res;
        for (int i = 0; i < n; ++i) {
            res.insert(findFather(i));
        }
        return stones.size() - res.size();
    }

private:
    int father[1001];
    
    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }
    
    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
};
```
