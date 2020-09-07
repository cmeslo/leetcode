# 952. Largest Component Size by Common Factor

## Disjoint set / Union find

```cpp
class DSU {
public:
    DSU(int n): _parents(n) {
        for (int i = 0; i < n; i++)
            _parents[i] = i;
    }
    
    int Find(int x) {
        if (x != _parents[x])
            _parents[x] = Find(_parents[x]);
        return _parents[x];
    }
    
    void Union(int a, int b) {
        _parents[Find(a)] = _parents[Find(b)];
    }
    
private:
    vector<int> _parents;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        DSU dsu(n + 1);
        
        for (int a : A) {
            int t= sqrt(a);
            for (int k = 2; k <= t; ++k) {
                if (a % k == 0) {
                    dsu.Union(a, k);
                    dsu.Union(a, a / k);
                }
            }
        }
        
        unordered_map<int, int> c;
        int ans = 1;
        for (int a : A)
            ans = max(ans, ++c[dsu.Find(a)]);
        
        return ans;
    }
};
```

reference: https://zxi.mytechroad.com/blog/graph/leetcode-952-largest-component-size-by-common-factor
