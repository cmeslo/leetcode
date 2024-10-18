class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = 'r';
            }
        }
        while (!st.empty()) {
            s[st.top()] = 'l';
            st.pop();
        }
        
        int left = 0, star = 0;
        for (char& c : s) {
            if (c == '*') {
                ++star;
            } else if (c == 'r') {
                if (star <= 0) return false;
                --star;
            } else if (c == 'l') {
                if (star >= 0) star = 0;
                --star;
            }
        }
        return star >= 0;
    }
};


// *)
// (*


// (*))
    
// (*r)

