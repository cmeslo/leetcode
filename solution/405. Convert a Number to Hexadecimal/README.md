# 405. Convert a Number to Hexadecimal
`num & 15` means `num mod 16`

`num >> 4` means `num / 16`

arithmetic shift right is not work for negative num, it will loop forever.

## Java:
* `>>` is arithmetic shift right.
  * The sign bit is extended to preserve the signedness of the number.

* `>>>` is logical shift right.
  * it simply moves everything to the right and fills in from the left with 0s.

## C:
* arithmetic shift right.
  * num `>>` 4;
* logical shift right.
  * (unsigned int) num `>>` 4;

~~~C++
    string toHex(int num) {
        if (num == 0) return "0";
        string map = "0123456789abcdef";
        // vector<char> map = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        string result = "";
        
        while (num != 0) {
            result = map[num & 15] + result;
            num = (unsigned int) num >> 4;
        }
        return result;
    }
~~~
