class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for (int i = pref.size() - 1; i >= 1; --i) {
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};

// pref[i] = pref[i-1] ^ nums[i]
// nums[i] = pref[i] ^ pref[i-1]
