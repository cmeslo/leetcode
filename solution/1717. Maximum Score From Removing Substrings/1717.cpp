class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;

        string st;
        bool ab = x > y;
        for (char& c : s) {
            bool push = true;
            if (!st.empty() && (c == 'a' || c == 'b')) {
                if (ab) {
                    if (st.back() == 'a' && c == 'b') {
                        st.pop_back();
                        res += x;
                        push = false;
                    }
                } else {
                    if (st.back() == 'b' && c == 'a') {
                        st.pop_back();
                        res += y;
                        push = false;
                    }
                }
            }
            if (push) st.push_back(c);
        }

        string st2;
        for (char& c : st) {
            bool push = true;
            if (!st2.empty() && (c == 'a' || c == 'b')) {
                if (ab) {
                    if (st2.back() == 'b' && c == 'a') {
                        st2.pop_back();
                        res += y;
                        push = false;
                    }
                } else {
                    if (st2.back() == 'a' && c == 'b') {
                        st2.pop_back();
                        res += x;
                        push = false;
                    }
                }
            }
            if (push) st2.push_back(c);
        }

        return res;
    }
};

// ab -> x
// ba -> y
// aba -> get(ba) -> a
//     -> get(ab) -> a
// bab -> get(ab) -> b
//     -> get(ba) -> b

// cdbcbaabab -> ba = 5
// cdbcabab -> ba = 5
// cdbcab -> ab = 4
// cdbc -> ab = 4

// cdbcbaabab -> ba = 5
// cdbcabab -> ba = 5
// cdbcab -> ba = 5
// cdbc -> ab = 4
