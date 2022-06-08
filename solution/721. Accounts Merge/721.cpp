class UFS {
public:
    vector<int> parents_, ranks_;
    
    UFS(int n): parents_(n), ranks_(n) {
        for (int i = 0; i < n; ++i)
            parents_[i] = i;
    }
    
    int Find(int x) {
        if (x != parents_[x])
            parents_[x] = Find(parents_[x]);
        return parents_[x];
    }
    
    void Union(int a, int b) {
        a = Find(a), b = Find(b);
        if (ranks_[a] < ranks_[b])
            parents_[a] = b;
        else if (ranks_[b] < ranks_[a])
            parents_[b] = a;
        else {
            parents_[b] = a;
            ranks_[a]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> indexMap;
        unordered_map<int, string> nameMap;
        for (auto& ac : accounts) {
            for (int i = 1; i < ac.size(); ++i) {
                if (!indexMap.count(ac[i]))
                    indexMap[ac[i]] = indexMap.size();
                nameMap[indexMap[ac[i]]] = ac[0];
            }
        }
        
        int n = indexMap.size();
        UFS ufs(n);
        for (auto& ac : accounts) {
            for (int i = 2; i < ac.size(); ++i) {
                ufs.Union(indexMap[ac[1]], indexMap[ac[i]]);
            }
        }
        
        unordered_map<int, vector<string>> res;
        for (auto& [email, index] : indexMap) {
            res[ufs.Find(index)].push_back(email);
        }
        vector<vector<string>> ans;
        for (auto& [root, list] : res) {
            sort(list.begin(), list.end());
            vector<string> cur;
            cur.push_back(nameMap[root]);
            for (string& email : list)
                cur.push_back(email);
            ans.push_back(cur);
        }
        return ans;
    }
};


// "tom": {a, [b], c}
// "tom": {[b], d}

// a-b-c
//    \
//     d

// "tom": {a, b, c, d}

