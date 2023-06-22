class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size())
            return gcdOfStrings(str2, str1);
        
        for (int l = str2.size(); l >= 1; --l) {
            if (checkOK(str1, str2, l))
                return str2.substr(0, l);
        }
        return "";
    }
    
private:
    bool checkOK(string& A, string& B, int len) {
        if (A.size() % len || B.size() % len) return false;
        
        string d = B.substr(0, len);
        
        string a = "";
        int n = A.size() / len;
        for (int i = 0; i < n; ++i)
            a.append(d);
        
        if (a != A) return false;
        
        n = B.size() / len;
        string b = "";
        for (int i = 0; i < n; ++i)
            b.append(d);
        if (b != B) return false;
        
        return true;
    }
};
