class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> A(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i])
                A[i] = A[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                A[i] = max(A[i], A[i + 1] + 1);
        }
        return accumulate(A.begin(), A.end(), 0);
    }
};
