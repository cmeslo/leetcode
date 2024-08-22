class Solution {
public:
    int getCommon(vector<int>& A, vector<int>& B) {
        for (int i = 0, j = 0; i < A.size() && j < B.size();) {
            if (A[i] == B[j])
                return A[i];
            if (A[i] < B[j])
                i += 1;
            else
                j += 1;
        }
        return -1;
    }
};
