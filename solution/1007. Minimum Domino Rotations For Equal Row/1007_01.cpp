class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) return -1;
        return min(helper(A, B), helper(B, A));
    }
    
private:
    int helper(vector<int>& A, vector<int>& B) {
        int a = 0, b = 1; // a is count of fixed A[0], b is count of fixed A[0] after swap(A[0], B[0])
        for (int i = 1; i < A.size(); ++i) {
            if ((A[0] != A[i] && B[0] != A[i]) && (A[0] != B[i] && B[0] != B[i]))
                return -1;

            if (a != INT_MAX && A[0] != A[i])
                a = A[0] == B[i] ? a + 1 : INT_MAX;

            if (b != INT_MAX && B[0] != A[i])
                b = B[0] == B[i] ? b + 1 : INT_MAX;
        }
        
        int ans = min(a, b);
        return ans == INT_MAX ? -1 : ans;
    }
};
