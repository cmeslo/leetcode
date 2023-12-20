class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(count(answerKey, k, 'T'), count(answerKey, k, 'F'));
    }
    
    int count(const string& A, int k, char key) {
        int res = 0, i = 0;
        for (int j = 0; j < A.size(); ++j) {
            if (A[j] == key) {
                k--;
                while (k < 0) {
                    if (A[i] == key)
                        k++;
                    i++;
                }
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
