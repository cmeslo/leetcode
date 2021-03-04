class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1 = 0, arrIdx1 = 0;
        int idx2 = 0, arrIdx2 = 0;
        while (arrIdx1 < word1.size() && arrIdx2 < word2.size()) {
            if (word1[arrIdx1][idx1] != word2[arrIdx2][idx2]) return false;
            idx1 = (idx1 + 1) % word1[arrIdx1].size();
            idx2 = (idx2 + 1) % word2[arrIdx2].size();
            if (idx1 == 0) ++arrIdx1;
            if (idx2 == 0) ++arrIdx2;
        }
        return arrIdx1 == word1.size() && arrIdx2 == word2.size();
    }
};
