class UFS {
public:
    vector<int> parent;
    UFS(int n): parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    };
    
    void merge(int i, int j) {
        i = find(i), j = find(j);
        if (i < j)
            parent[j] = i;
        else
            parent[i] = j;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        UFS ufs(n);
        for (int i = 0; i < n; ++i) {
            if (ufs.find(i) != ufs.find(nums[i]))
                ufs.merge(i, nums[i]);
        }
        int res = 0;
        unordered_map<int, int> m;
        for (int x : nums) {
            int parent_x = ufs.find(x);
            res = max(res, ++m[parent_x]);
        }
        return res;
    }
};
