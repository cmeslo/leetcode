# 1202. Smallest String With Swaps

## Solution: Union Find

```cpp
// Runtime: 215 ms, Your runtime beats 88.10 % of cpp submissions.
// Memory Usage: 51.9 MB, Your memory usage beats 66.50 % of cpp submissions.

class Solution {
private:
    int father[100001];
    
    int FindFather(int i) {
        if (i != father[i])
            father[i] = FindFather(father[i]);
        return father[i];
    }
    
    void Union(int i, int j) {
        i = FindFather(i);
        j = FindFather(j);
        if (i < j)
            father[j] = i;
        else
            father[i] = j;
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
        
        for (auto p : pairs) {
            int a = p[0], b = p[1];
            if (FindFather(a) != FindFather(b))
                Union(a, b);
        }
        
        unordered_map<int, priority_queue<char, vector<char>, greater<>>> groups;
        for (int i = 0; i < n; ++i) {
            groups[FindFather(i)].push(s[i]);
        }
        
        string ans = "";
        for (int i = 0; i < n; ++i) {
            auto& pq = groups[FindFather(i)];
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
```

or

```cpp
// Runtime: 250 ms, Your runtime beats 81.84 % of cpp submissions.
// Memory Usage: 53 MB, Your memory usage beats 60.98 % of cpp submissions.

class Solution {
private:
    vector<int> father;
    
    int FindFather(int i) {
        if (i != father[i])
            father[i] = FindFather(father[i]);
        return father[i];
    }
    
    void Union(int i, int j) {
        i = FindFather(i);
        j = FindFather(j);
        if (i < j)
            father[j] = i;
        else
            father[i] = j;
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        
        father.resize(n);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
        
        for (auto p : pairs) {
            int a = p[0], b = p[1];
            if (FindFather(a) != FindFather(b))
                Union(a, b);
        }
        
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[FindFather(i)].push_back(i);
        }
        
        for (auto& [root, arr] : groups) {
            string tmp = "";
            for (int i : arr)
                tmp.push_back(s[i]);
            
            sort(tmp.begin(), tmp.end());
            
            int j = 0;
            for (int i : arr)
                s[i] = tmp[j++];
        }
        return s;
    }
};
```
