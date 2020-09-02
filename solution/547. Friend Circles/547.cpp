class UFS {
public:
    UFS(int n): _parents(n+1), _ranks(n+1, 0) {
        for (int i = 0; i < n; ++i)
            _parents[i] = i;
    }
    
    int Find(int i) {
        if (i != _parents[i])
            _parents[i] = Find(_parents[i]);
        return _parents[i];
    }
    
    bool Union(int i, int j) {
        int ri = Find(i), rj = Find(j);
        if (ri == rj) return false;
        
        if (_ranks[ri] < _ranks[rj])
            _parents[ri] = _parents[rj];
        else if (_ranks[rj] < _ranks[ri])
            _parents[rj] = _parents[ri];
        else {
            _parents[rj] = _parents[ri];
            _ranks[ri]++;
        }
        
        return true;
    }
    
private:
    vector<int> _parents;
    vector<int> _ranks;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UFS ufs(n);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (M[i][j] == 1) ufs.Union(i, j);
        
        unordered_set<int> circles;
        for (int i = 0; i < n; ++i)
            circles.insert(ufs.Find(i));
        
        return circles.size();
    }
};
