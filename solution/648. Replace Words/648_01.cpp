class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> D(dictionary.begin(), dictionary.end());
        
        istringstream iss(sentence);
        string res, w;
        while (iss >> w) {
            bool ok = false;
            for (int len = 1; len <= w.size() && !ok; ++len) {
                string sub = w.substr(0, len);
                if (D.count(sub)) {
                    res += sub + " ";
                    ok = true;
                }
            }
            if (!ok)
                res += w + " ";
        }
        
        res.pop_back();
        return res;
    }
};
