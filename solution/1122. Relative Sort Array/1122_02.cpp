class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        vector<int> cnt(1001);
        for (int x : A)
            cnt[x]++;
        
        int i = 0;
        for (int x : B) {
            while (cnt[x]-- > 0)
                A[i++] = x;
        }
        for (int x = 0; x < cnt.size(); ++x) {
            while (cnt[x]-- > 0)
                A[i++] = x;
        }
        return A;
    }
};
