class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        int n = A.size();
        unordered_map<int, int> m1, m2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ++m1[A[i] + B[j]];
                ++m2[C[i] + D[j]];
            }
        }
        
        for (auto i : m1) {
            ans += i.second * m2[-i.first];
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