class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        
        for (auto& e : edges)
            merge(e[0], e[1]);
        
        return findFather(source) == findFather(destination);
    }
    
private:
    vector<int> father;
    
    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }
    
    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
};
