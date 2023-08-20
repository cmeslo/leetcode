class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> res;
        for (int x : spells) {
            int l = 0, r = n, m;
            while (l < r) {
                m = l + (r - l) / 2;
                if (1L * x * potions[m] < success)
                    l = m + 1;
                else
                    r = m;
            }
            res.push_back(n - l);
        }
        return res;
    }
};
