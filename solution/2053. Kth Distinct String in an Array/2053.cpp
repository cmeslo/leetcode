class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (string& x : arr)
            m[x]++;
        
        for (string& x : arr) {
            if (m[x] == 1) {
                if (--k == 0)
                    return x;
            }
        }
        return "";
    }
};
