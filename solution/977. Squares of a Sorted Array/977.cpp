class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int index = n - 1;
        int p1 = 0, p2 = n - 1;
        
        while (p1 <= p2) {
            if (abs(A[p1]) < abs(A[p2])) {
                ans[index--] = A[p2] * A[p2];
                p2--;
            } else {
                ans[index--] = A[p1] * A[p1];
                p1++;
            }
        }
        
        return ans;
    }
};
