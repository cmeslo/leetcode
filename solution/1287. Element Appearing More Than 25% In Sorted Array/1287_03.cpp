class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int n = arr.size();
        vector<int> A { arr[n/4], arr[n/2], arr[n*3/4] }; // 斬開4份, 只有這3個數有可能是答案
        for (int x : A) {
            int l = firstOccurence(arr, x);
            int r = lastOccurence(arr, x);
            if ((r - l + 1) > n / 4)
                return x;
        }
        return -1;
    }
    
    int firstOccurence(vector<int>& arr, int val) {
        int l = 0, r = arr.size(), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (arr[m] < val)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
    
    int lastOccurence(vector<int>& arr, int val) {
        int l = 0, r = arr.size(), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (arr[m] <= val)
                l = m + 1;
            else
                r = m;
        }
        return l - 1;
    }
};
