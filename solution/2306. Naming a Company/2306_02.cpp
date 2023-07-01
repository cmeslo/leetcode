class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> count[26];
        for (string& s : ideas) {
            count[s[0] - 'a'].insert(s.substr(1));
        }
        
        long long res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                long long c1 = 0, c2 = 0; // suffix count
                for (auto& suffix : count[i])
                    if (!count[j].count(suffix)) ++c1;
                for (auto& suffix : count[j])
                    if (!count[i].count(suffix)) ++c2;
                res += c1 * c2;
            }
        }
        return res * 2;
    }
};
