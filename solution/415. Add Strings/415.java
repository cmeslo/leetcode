class Solution {
    public String addStrings(String num1, String num2) {
        int s1 = num1.length() - 1, s2 = num2.length() - 1;
        int carry = 0;
        StringBuilder sb = new StringBuilder();
        
        while (s1 >= 0 || s2 >= 0) {
            int n1 = s1 >= 0 ? num1.charAt(s1--) - '0' : 0;
            int n2 = s2 >= 0 ? num2.charAt(s2--) - '0' : 0;
            int sum = n1 + n2 + carry;
            sb.append(sum % 10);
            carry = sum / 10;
        }
        String res = sb.reverse().toString();
        return carry != 0 ? "1" + res : res;
    }
}
