# 299. Bulls and Cows

分兩種情況：

1. 猜中了的時候 a++
2. 猜不中的時候，分別記錄下 猜了甚麼(guess_vector)，以及 該位置的答案(secret_vector)是甚麼

最後 guess_vector 和 secret_vector 取短板，構成 b

```cpp
string getHint(string secret, string guess) {
    int a = 0, b = 0;
    vector<int> s_v(10, 0), g_v(10, 0);

    for (int i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            a++;
        } else {
            s_v[secret[i] - '0']++;
            g_v[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < s_v.size(); ++i)
        b += min(s_v[i], g_v[i]);

    return to_string(a) + 'A' + to_string(b) + 'B';
}
```
