class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int x : arr)
            ++m[x];
        
        vector<int> A;
        for (auto [x, cnt] : m)
            A.push_back(cnt);
        
        sort(A.rbegin(), A.rend());
        
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            cnt += A[i];
            if (cnt >= arr.size() / 2)
                return i + 1;
        }
        return -1;
    }
};
