class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        istringstream iss1(s1), iss2(s2);
        string w;
        while (iss1 >> w) {
            m[w]++;
        }
        
        while (iss2 >> w) {
            m[w]++;
        }
        
        vector<string> res;
        for (auto [w, cnt] : m) {
            if (cnt == 1) {
                res.push_back(w);
            }
        }
        return res;
    }
};
