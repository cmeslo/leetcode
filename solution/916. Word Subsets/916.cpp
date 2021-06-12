class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        
        vector<int> compressedB(26);
        for (string b : B) {
            vector<int> temp(26);
            for (char c : b)
                ++temp[c - 'a'];
            for (int i = 0; i < 26; ++i)
                compressedB[i] = max(compressedB[i], temp[i]);
        }
        
        for (const string& a : A) {
            if (check(a, compressedB))
                ans.push_back(a);
        }
        return ans;
    }
    
private:
    bool check(const string& a, vector<int>& B) {
        vector<int> letters(26);
        for (char c : a)
            ++letters[c - 'a'];
        
        for (int i = 0; i < 26; ++i) {
            if (B[i] == 0) continue;
            if (letters[i] < B[i])
                return false;
        }

        return true;
    }
};
