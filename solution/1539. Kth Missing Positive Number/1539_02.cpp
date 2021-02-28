class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            if (arr[i] - (i + 1) >= k)
                return i + k;
        
        return n + k;
    }
};
