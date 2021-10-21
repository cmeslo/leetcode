class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i = 0;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it != arr.end()) {
            if (it != arr.begin() && abs(x - *prev(it)) <= abs(x - *it))
                it = prev(it);
            i = it - arr.begin();
        } else {
            i = n - 1;
        }
        
        int l = i, r = i;
        while (r - l + 1 < k) {
            if (l-1 >= 0 && r+1 < n) {
                if (x - arr[l-1] > arr[r+1] - x)
                    r++;
                else
                    l--;
            } else if (l-1 >= 0) {
                l--;
            } else if (r+1 < n) {
                r++;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
