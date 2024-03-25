class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int x : arr) {
            if (++m[x] > n / 4)
                return x;
        }
        return -1;
    }
};
