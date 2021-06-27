class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26);
        for (int i = 0; i < order.size(); ++i)
            dict[order[i] - 'a'] = i;
        
        for (int i = 0; i < words.size() - 1; ++i)
            if (!smaller(words[i], words[i + 1], dict))
                return false;
        return true;
    }

private:
    bool smaller(const string& a, const string& b, const vector<int>& dict) {
        int lenA = a.size(), lenB = b.size();
        for (int i = 0; i < min(lenA, lenB); ++i) {
            if (dict[a[i] - 'a'] < dict[b[i] - 'a']) return true;
            if (dict[a[i] - 'a'] > dict[b[i] - 'a']) return false;
        }
        return a.size() <= b.size();
    }
};
