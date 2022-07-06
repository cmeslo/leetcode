class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int diff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            diff = min(diff, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] == diff)
                res.push_back({arr[i - 1], arr[i]});
        }
        
        return res;
    }
};
