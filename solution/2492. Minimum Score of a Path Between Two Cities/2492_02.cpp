class Solution {
private:
    vector<int> father;
    
    int find(int x) {
        if (x != father[x])
            father[x] = find(father[x]);
        return father[x];
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads) {
        father.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            father[i] = i;
        
        for (auto& r : roads) {
            merge(r[0], r[1]);
        }
        
        int res = INT_MAX;
        for (auto& r : roads) {
            int a = r[0], score = r[2];
            if (find(1) == find(a))
                res = min(res, score);
        }
        return res;
    }
};
