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
