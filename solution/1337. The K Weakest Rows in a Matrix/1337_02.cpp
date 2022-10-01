class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> A;
        for (int i = 0; i < m; ++i) {
            int soldiers = 0;
            for (int j = 0; j < n && mat[i][j] == 1; ++j) {
                soldiers++;
            }
            A.push_back({soldiers, i});
        }
        
        sort(A.begin(), A.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(A[i].second);
        }
        return ans;
    }
};
