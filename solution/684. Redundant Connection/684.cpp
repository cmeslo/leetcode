class UFS {
public:
    UFS(int n): parents_(n + 1), ranks_(n + 1, 0) {
        for (int i = 1; i <= n; ++i)
            parents_[i] = i;
    };
    
    int Find(int i) {
        if (parents_[i] != i)
            parents_[i] = Find(parents_[i]);
        return parents_[i];
    }
    
    void Union(int i, int j) {
        int ri = Find(i), rj = Find(j);
        if (ranks_[ri] < ranks_[rj])
            parents_[ri] = rj;
        else if (ranks_[rj] < ranks_[ri])
            parents_[rj] = ri;
        else {
            parents_[rj] = ri;
            ranks_[ri]++;
        }
    }

private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UFS ufs(n);
        for (auto& edge : edges) {
            if (ufs.Find(edge[0]) == ufs.Find(edge[1]))
                return edge;
            else
                ufs.Union(edge[0], edge[1]);
        }
        return {};
    }
};
