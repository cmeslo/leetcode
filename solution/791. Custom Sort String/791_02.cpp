class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char, int> m;
        for (char& c : str)
            m[c]++;
        
        string ans;
        for (char& c : order) {
            ans += string(m[c], c);
            m[c] = 0;
        }
        
        for (auto& [c, count] : m)
            ans += string(count, c);
        
        return ans;
    }
};
