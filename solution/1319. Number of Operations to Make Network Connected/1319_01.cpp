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
    int makeConnected(int n, vector<vector<int>>& connections) {
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        
        int cable = 0;
        for (auto& c : connections) {
            int a = c[0], b = c[1];
            if (find(a) == find(b))
                cable++;
            else
                merge(a, b);
        }
        
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (find(0) != find(i)) {
                if (cable-- <= 0) return -1;
                res++;
                merge(0, i);
            }
        }
        return res;
    }
};
