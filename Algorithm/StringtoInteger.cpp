/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
    int myAtoi(string str) {
             if (str.size() == 0) {
                 return 0;
             }
             int i = 0;
             while (i < str.size() && str[i] == ' ') {
                 i++;
             }
             if (i == str.size()) {
                 return 0;
             }
             int sign = 1;
             int result = 0;            
             if (str[i] == '-') {
                 sign = -1;
                 i++;
             } else if (str[i] == '+') {
                 i++;
             }
             for (int j = i; j < str.size(); j ++) {
                 if (str[j] >= '0' && str[j] <= '9') {
                     int tmp = str[j] - '0';
                     if ((sign == 1 && result > (INT_MAX - tmp) / 10))
                         return INT_MAX;
                     else if (sign == -1 && (result  * sign < (INT_MIN + tmp) / 10 || result * sign * 10 - tmp == INT_MIN))
                         return INT_MIN;
                     result = result * 10 + tmp;
                 } else {
                     return result * sign;
                }
             }
             return result * sign;
    }
};
