class UFS {
private:
    vector<int> father;
public:
    UFS(int n): father(n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (a < b) {
            father[b] = a;
        } else {
            father[a] = b;
        }
    }
    
    int find(int x) {
        if (x != father[x])
            father[x] = find(father[x]);
        return father[x];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UFS ufs(26);
        for (auto& e : equations)
            if (e[1] == '=')
                ufs.merge(e[0] - 'a', e[3] - 'a');
        
        for (auto& e : equations)
            if (e[1] == '!' && ufs.find(e[0] - 'a') == ufs.find(e[3] - 'a'))
                return false;
        
        return true;
    }
};
