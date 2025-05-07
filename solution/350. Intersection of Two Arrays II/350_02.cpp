class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j])
                ++i;
            else if (A[i] > B[j])
                ++j;
            else {
                ans.push_back(A[i]);
                ++i, ++j;
            }
        }
        return ans;
    }
};
