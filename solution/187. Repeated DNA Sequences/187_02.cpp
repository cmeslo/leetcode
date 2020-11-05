class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        
        unordered_set<string> ans;
        unordered_set<string_view> seqs;
        string_view sv(s);
        
        for (int start = 0; start + 9 < sv.length(); ++start) {
            string_view sub = sv.substr(start, 10);
            if (seqs.find(sub) != seqs.end())
                ans.insert(string(sub));
            else
                seqs.insert(sub);
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
};
