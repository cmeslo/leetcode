# 952. Largest Component Size by Common Factor

## Disjoint set / Union find

### C++

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

### java

```java
class UFS {
    private int[] parents;
    
    UFS(int n) {
        parents = new int[n];
        for (int i = 0; i < n; ++i)
            parents[i] = i;
    }
    
    public int Find(int x) {
        if (x != parents[x])
            parents[x] = Find(parents[x]);
        return parents[x];
    }
    
    public void Union(int a, int b) {
        parents[Find(a)] = Find(b);
    }
}

class Solution {
    public int largestComponentSize(int[] nums) {
        int mx = 0;
        for (int x : nums) mx = Math.max(mx, x);
        UFS ufs = new UFS(mx + 1);
        
        for (int x : nums) {
            int t = (int)Math.sqrt(x);
            for (int j = 2; j <= t; ++j) {
                if (x % j == 0) {
                    ufs.Union(x, j);
                    ufs.Union(x, x / j);
                }
            }
        }
        
        int res = 0;
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        for (int x : nums) {
            int root = ufs.Find(x);
            if (!m.containsKey(root))
                m.put(root, 1);
            else
                m.put(root, m.get(root) + 1);
            res = Math.max(res, m.get(root));
        }
        return res;
    }
}
```

reference: https://zxi.mytechroad.com/blog/graph/leetcode-952-largest-component-size-by-common-factor
