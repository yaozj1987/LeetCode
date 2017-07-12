/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x)
    {
        int y = 0;
        while (x)
        {
            // 正常应该 INT_MAX - x % 10 来判断，只是实际上的int类型不会有这种case出现而已
            // INT_MIN - x % 10
            if (y > INT_MAX / 10 || y < INT_MIN / 10)
                return 0;
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return  y;

    }
};
