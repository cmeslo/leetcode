class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<int> listA, listB;
        
        for (int i = 0; i < n*n; ++i) {
            if (A[i / n][i % n] == 1) listA.push_back(i / n * 100 + i % n);
            if (B[i / n][i % n] == 1) listB.push_back(i / n * 100 + i % n);
        }
        
        unordered_map<int, int> v; // 向量
        for (int a : listA)
            for (int b : listB)
                ++v[a - b];
        
        int ans = 0;
        for (auto& it : v)
            ans = max(ans, it.second);
        
        return ans;
    }
};
