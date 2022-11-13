class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                if (FindFather(i) == FindFather(j)) return false;
                Union(graph[i][0], j);
            }
        }
        return true;
    }

private:
    vector<int> father;
    
    int FindFather(int a) {
        if (a != father[a])
            father[a] = FindFather(father[a]);
        return father[a];
    }
    
    void Union(int a, int b) {
        if (father[a] == father[b]) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
};
