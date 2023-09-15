class Solution {
private:
    vector<int> father;
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
    
    int find(int x) {
        if (x != father[x])
            return father[x] = find(father[x]);
        return father[x];
    }
    
    bool similar(string& A, string& B) {
        int n = A.size();
        int diff = 0;
        vector<int> f(26);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[i] && ++diff > 2)
                return false;
        }
        return true;
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (similar(strs[i], strs[j]))
                    merge(i, j);
            }
        }
        
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(find(i));
        }
        return s.size();
    }
};
