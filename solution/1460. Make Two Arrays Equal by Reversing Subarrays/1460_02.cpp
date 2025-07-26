class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int count[1001];
        for (int i = 0; i < arr.size(); ++i) {
            count[arr[i]]++;
            count[target[i]]--;
        }
        for (int i = 0; i < 1001; ++i)
            if (count[i] != 0)
                return false;
        return true;
    }
};
