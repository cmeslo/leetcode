class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.empty() || k < arr[0]) return k;
        
        int pre = 0;
        for (int cur : arr) {
            if (cur - pre - 1 >= k)
                return pre + k;
            k -= cur - pre - 1;
            pre = cur;
        }
        return arr.back() + k;
    }
};
