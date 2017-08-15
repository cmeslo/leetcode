class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        int n = A.size();
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ++m[A[i] + B[j]];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += m[-C[i]-D[j]];
            }
        }

        return ans;
    }
};

int main() {
    Solution* sol = new Solution;
    
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    
    std::cout << sol->fourSumCount(A, B, C, D) << std::endl;
}