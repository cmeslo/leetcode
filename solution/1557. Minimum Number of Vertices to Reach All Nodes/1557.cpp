class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> D(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            D[b]++;
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (D[i] == 0)
                res.push_back(i);
        return res;
    }
};
