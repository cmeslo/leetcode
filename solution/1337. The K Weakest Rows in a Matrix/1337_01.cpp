class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            // int j = 0;
            // while (j < n && mat[i][j] != 0) ++j;
            int j = countSolider(mat[i]);
            q.emplace(j, i);
            if (q.size() > k) q.pop();
        }
        
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }
    
private:
    int countSolider(vector<int>& row) {
        int l = 0, r = row.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (row[m] == 0)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
