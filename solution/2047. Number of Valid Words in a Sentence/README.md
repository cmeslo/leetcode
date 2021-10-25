# 2047. Number of Valid Words in a Sentence

```cpp
int countValidWords(string sentence) {
    istringstream ss(sentence);
    string w;

    int res = 0;
    while (ss >> w) {
        bool isOK = true;
        int hyphen = 0, punctuation = 0;
        for (int i = 0; i < w.size() && isOK; ++i) {
            if (w[i] == '-') {
                if (i == 0 || i == w.size() - 1) isOK = false;
                if (i == w.size() - 2 && !isalpha(w.back())) isOK = false;
                if (++hyphen > 1) isOK = false;
            } else if (isdigit(w[i])) {
                isOK = false;
            } else if (w[i] == '!' || w[i] == '.' || w[i] == ',') {
                if (i != w.size() - 1) isOK = false;
                if (++punctuation > 1) isOK = false;
            }
        }
        if (isOK) ++res;
    }
    return res;
}
```
