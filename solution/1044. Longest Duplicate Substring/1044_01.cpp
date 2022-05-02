#define p 10000007

class Solution {
public:
    string longestDupSubstring(string S) {
        int len = S.size();
        if (len == 0) return "";

        roll.resize(len);
        roll[0] = 1;
        for (int i = 1; i < len; i++) roll[i] = (roll[i-1]*26) % p;

        int left = 1, right = len, mid; // left cannot be 0, because window size (mid) cannot be 0.
        
        while (left < right) {
            mid = left + (right-left)/2;
            string temp = "";
            
            if (search(S, len, mid, temp) == true) {
                if (temp.size() > ans.size()) ans = temp;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return ans;
    }
private:
    vector<int> roll;
    string ans;

    bool search(const string& s, int len, int size, string& ans) {
        unordered_map<int, vector<int>> m;

        int hash = 0;
        for (int i = 0; i < size; i++) {
            hash = (hash + (toInt(s[i])*roll[size-i-1])%p) % p;
        }
        m[hash].push_back(0);

        for (int i = size; i < len; i++) {
            int rm = i - size;
            hash = ((hash - toInt(s[rm])*roll[size-1])%p + p) % p; // add mod to avoid negative value
            hash = (hash*26 + toInt(s[i])%p) % p;

            if (m.find(hash) != m.end()) {

                string curr = s.substr(rm+1, size);
                for (auto start : m[hash]) {
                    string temp = s.substr(start, size);
                    if (curr.compare(temp) == 0) {
                        ans = temp;
                        return true;
                    }
                }

            } else {
                m[hash].push_back(rm + 1);
            }
        }
        return false;
    }

    int toInt(const char& c) {
        return c - 'a';
    }
};
