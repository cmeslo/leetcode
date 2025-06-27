class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n = names.size();
        
        vector<pair<int, string>> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = {heights[i], names[i]};
        
        sort(A.rbegin(), A.rend());
        
        for (int i = 0; i < n; ++i)
            names[i] = A[i].second;
        return names;
    }
};
