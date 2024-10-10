class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }
    
private:
    string encode(const string& s) {
        string res = "";
        unordered_map<char, char> m;
        char a = 'a';
        for (const char& c : s) {
            if (!m.count(c)) {
                m[c] = a;
                a += 1;
            }
            res += m[c];
        }
        return res;
    }
};
