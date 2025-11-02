class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        istringstream iss(s1 + " " + s2);
        string w;
        while (iss >> w) {
            m[w]++;
        }
        
        vector<string> res;
        for (auto& [w, cnt] : m) {
            if (cnt == 1)
                res.push_back(w);
        }
        return res;
    }
};
