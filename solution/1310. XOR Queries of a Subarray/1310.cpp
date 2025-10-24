class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> A(n);
        A[0] = arr[0];
        for (int i = 1; i < n; ++i)
            A[i] = A[i - 1] ^ arr[i];
        
        vector<int> res;
        for (auto& q : queries) {
            int i = q[0], j = q[1];
            res.push_back(i > 0 ? A[j] ^ A[i - 1] : A[j]);
        }
        return res;
    }
};
