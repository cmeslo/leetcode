class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A)
            reverse(begin(row), end(row));
        
        for (auto& row : A)
            for (int& i : row)
                i ^= 1;
        
        return A;
    }
};
