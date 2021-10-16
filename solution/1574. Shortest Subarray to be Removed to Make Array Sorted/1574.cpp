class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n - 1;
        while (j-1 >= 0 && arr[j-1] <= arr[j]) --j;
        
        int res = j;
        for (int i = 0; i < j; ++i) {
            if (i && arr[i-1] > arr[i]) break;
            while (j < n && arr[i] > arr[j]) ++j;
            res = min(res, j - i - 1);
        }
        return res;
    }
};
