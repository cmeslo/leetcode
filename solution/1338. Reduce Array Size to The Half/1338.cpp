class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int x : arr) m[x]++;
        
        vector<int> freq;
        for (auto [num, count] : m)
            freq.push_back(count);
        sort(freq.rbegin(), freq.rend());
        
        int ans = 0;
        int removed = 0, n = arr.size();
        for (int f : freq) {
            ++ans;
            removed += f;
            if (removed >= n / 2) break;
        }
        return ans;
    }
};
