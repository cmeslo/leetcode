# 721. Accounts Merge

## Solution: Union find

### 寫法一

```cpp
// 92 ms, Your runtime beats 95.46 % of cpp submissions.

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


```

### 寫法二

```cpp
// 156 ms, Your runtime beats 60.69 % of cpp submissions.

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 1. initialization
        for (auto& ac : accounts) {
            for (int i = 1; i < ac.size(); ++i) {
                father[ac[i]] = ac[i];
                owner[ac[i]] = ac[0];
            }
        }
        
        // 2. union
        for (auto& ac : accounts) {
            for (int i = 2; i < ac.size(); ++i) {
                Union(ac[i - 1], ac[i]);
            }
        }
        
        // 3. build ans
        for (auto& [email, name] : owner) {
            string root = Find(email);
            group[root].insert(email);
        }
        vector<vector<string>> res;
        for (auto& [root, emailSet] : group) {
            vector<string> cur;
            cur.push_back(owner[root]);
            for (string email : emailSet)
                cur.push_back(email);
            res.push_back(cur);
        }
        return res;
    }
    
private:
    unordered_map<string, string> father;
    unordered_map<string, string> owner;
    unordered_map<string, set<string>> group;
    
    string Find(string x) {
        if (x != father[x])
            father[x] = Find(father[x]);
        return father[x];
    }
    
    void Union(string a, string b) {
        a = Find(a), b = Find(b);
        if (a == b) return;
        if (a < b)
            father[a] = b;
        else
            father[b] = a;
    }
};
```
