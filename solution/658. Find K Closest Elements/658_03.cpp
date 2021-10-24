class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - k;
        while (low < high) {
            int left = low + (high - low) / 2;
            if (x - arr[left] <= arr[left + k] - x)
                high = left;
            else
                low = left + 1;
        }
        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
