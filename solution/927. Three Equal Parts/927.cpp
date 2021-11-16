class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;
        for (int x : arr)
            if (x == 1) ++ones;
        if (ones == 0) return {0, n - 1};
        if (ones % 3) return {-1, -1};
        ones /= 3;
        
        int j = n;
        while (ones) {
            --j;
            if (arr[j] == 1) --ones;
        }
        
        int i = 0;
        while (arr[i] == 0) ++i;
        
        int k = j;
        while (k < n && arr[i] == arr[k]) {
            ++i, ++k;
        }
        if (k != n) return {-1, -1};
        
        vector<int> ans(2);
        ans[0] = i - 1;
        
        while (i < j && arr[i] == 0) ++i;
        k = j;
        while (k < n && arr[i] == arr[k]) {
            ++i, ++k;
        }
        if (k != n) return {-1, -1};
        
        ans[1] = i;
        return ans;
    }
};
