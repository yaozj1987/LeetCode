/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution {
public:
    bool isPalindrome(int x) {
             if (x < 0) return false;
             int y = 1;
             int tmp_x = x;
             //得到x的最高位 10xxxxx0
             while (tmp_x / 10) {
                 y *= 10;
                 tmp_x /= 10;
             }
             // 首尾开始遍历
             while (x) {
                 int tail = x % 10;
                 int head = x / y;
                 if (tail != head) {
                     return false;
                 }
                 x = x % y / 10;
                 y /= 100;
             }
             return true;
         }         
};
