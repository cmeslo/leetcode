# 165. Compare Version Numbers

## Solution: Two Pointers

```cpp
int compareVersion(string version1, string version2) {
    int n1 = version1.length(), n2 = version2.length();
    int i1 = 0, i2 = 0;

    while (i1 < n1 || i2 < n2) {
        int num1 = 0;
        while (i1 < n1 && version1[i1] != '.')
            num1 = num1 * 10 + (version1[i1++] - '0');

        int num2 = 0;
        while (i2 < n2 && version2[i2] != '.')
            num2 = num2 * 10 + (version2[i2++] - '0');

        if (num1 < num2) return -1;
        else if (num1 > num2) return 1;

        i1++;
        i2++;
    }

    return 0;
}
```

or

```cpp
int compareVersion(string version1, string version2) {
    vector<int> A, B;
    istringstream iss1(version1);
    string cur = "";
    while (getline(iss1, cur, '.'))
        A.push_back(stoi(cur));

    istringstream iss2(version2);
    while (getline(iss2, cur, '.'))
        B.push_back(stoi(cur));

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] > B[j])
            return 1;
        else if (A[i] < B[j])
            return -1;
        i++, j++;
    }
    while (i < A.size()) {
        if (A[i++] != 0)
            return 1;
    }
    while (j < B.size()) {
        if (B[j++] != 0)
            return -1;
    }
    return 0;
}
```
