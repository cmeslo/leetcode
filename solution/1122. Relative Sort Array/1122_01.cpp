class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); ++i)
            rank[arr2[i]] = i;
        
        sort(arr1.begin(), arr1.end(), [&rank](int a, int b) {
            if (!rank.count(a) && !rank.count(b)) return a < b;
            if (!rank.count(a)) return false;
            if (!rank.count(b)) return true;
            return rank[a] < rank[b];
        });
        
        return arr1;
    }
};
