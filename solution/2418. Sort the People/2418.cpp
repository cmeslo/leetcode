class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n = names.size();
        
        vector<pair<string, int>> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = {names[i], i};
        
        sort(A.begin(), A.end(), [&](auto& a, auto& b) {
            return heights[a.second] > heights[b.second];
        });
        
        for (int i = 0; i < n; ++i)
            names[i] = A[i].first;
        return names;
    }
};
