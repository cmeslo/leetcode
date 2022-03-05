class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, up = 1, down = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] < arr[i]) {
                up = down + 1;
                down = 1;
            } else if (arr[i - 1] > arr[i]) {
                down = up + 1;
                up = 1;
            } else {
                up = down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};
