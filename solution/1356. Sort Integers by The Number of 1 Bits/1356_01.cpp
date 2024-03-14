class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        const int n = arr.size();
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {__builtin_popcount(arr[i]), arr[i]};
        }
        sort(A.begin(), A.end());
        
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = A[i].second;
        return res;
    }
};
