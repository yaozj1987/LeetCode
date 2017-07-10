/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
            if (s.size() <= 1) {                                                  
                return s;
            }
            string result;
            // 记录最长回文子串的起始位置
            int pos = 0;
            // 记录长度
            int len = 1;
            // 用vecotor会超时
            int f[1001][1001] = {0};
            // 主对角线都为1
            for (size_t i = 0; i < s.size(); i ++) {
                f[i][i] = 1;
            }
            // dp方法 f[i][j] = 0 if s[i] != s[j]
            // = f[i+1][j-1] + 2 if s[i]=s[j] && f[i+1][j-1] > 0
            // 设置次对角线
            for (int i = s.size() - 1; i >= 0; i --) {
                 if (s[i] == s[i + 1]) {
                    f[i][i + 1] = 2;
                    pos = i;
                    len = 2;
                 } else {
                     f[i][i + 1] = 0;
                 }
            }
            // 设置上半三角的其他位置  f[1][3] 需要 f[2][2]  f[1][4] 需要 f[2][3] 每个都需要其左下点先确认值 
            for (size_t level = 2; level < s.size() ; level ++) {
               for (size_t i = 0; i < s.size() - level; i ++) {
                   int j = i + level;
                   if (f[i + 1][j - 1] != 0 && s[i] == s[j]) {
                        f[i][j] = f[i + 1][j - 1] + 2;
                        if (f[i][j] > len) {
                           pos = i;
                           len = f[i][j];
                        }
                    } else {
                        f[i][j] = 0;
                    }
                }
            }   
            result = s.substr(pos,len);
            return result;
    }
};
