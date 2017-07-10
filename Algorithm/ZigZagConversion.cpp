/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
        // 没有这个判断，下面的2 * numRows - 2可能越界，细节决定成败
        if (numRows <= 1)  return s;
        string result(s);
        // 画下标图帮助理解
        // 最上面一行和下面一行差距为2n - 2
        // 中间行每个中间还有一个下标，设j为该行第j个下标值（不算中间的那个下标值），则中间下标值为2n -2 + j - 2i （i为第i行）
        int index = 0;
        // 填第一行
        for (int i = 0; i < s.size(); i += 2 * numRows - 2) {
                result[index++] = s[i];
        }
        // 填中间行
        for (int i = 1; i < numRows - 1; i++) {
            int j = i;
            while (j < s.size()) {
                result[index++] = s[j];
                // 取中间下标
                if (2 * numRows - 2 + j - 2 * i < s.size()) {
                    result[index++] = s[2 * numRows - 2 + j - 2 * i];
                }
                j += 2*numRows -2;
            }
        }
        // 填最后一行
        for (int i = numRows - 1; i < s.size() && i != 0; i += 2 * numRows - 2) {
                result[index++] = s[i];
        }
        return result;
    }
};
