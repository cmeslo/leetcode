class Solution {
public:
    string addBinary(string a, string b) {
        int sizeA = a.size(), sizeB = b.size();
        string res(sizeA + sizeB, '0');
        
        int pos = sizeA + sizeB - 1;
        for (int i = sizeA - 1, j = sizeB - 1; i >= 0 || j >= 0; --i, --j, --pos) {
            char posA = i >= 0 ? a[i] : '0';
            char posB = j >= 0 ? b[j] : '0';
            
            if ((posA == '0' && posB == '1') || (posA == '1' && posB == '0')) {
                if (res[pos] == '1') {
                    res[pos - 1] = '1';
                    res[pos] = '0';
                } else {
                    res[pos] = '1';
                }
            } else if (posA == '1' && posB == '1') {
                res[pos - 1] = '1';
                res[pos] = res[pos] == '1' ? '1' : '0';
            }
        }
        size_t startPos = res.find_first_not_of("0");
        if (startPos != std::string::npos) return res.substr(startPos);
        return "0";
    }
};
