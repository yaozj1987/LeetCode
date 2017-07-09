
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int max_f = 1;
        // 以i结尾的最长长度
        int f = 1;
        for (int i = 1; i < s.size(); i++) {
            int j = i - 1;
            // can use a map handle follow
            for (; j >= i - f; j--) {
                if (s[j] == s[i]) {
                    break;
                }
            }
            f = i - j;
            if (f > max_f) {
                max_f = f;
            }                                                                                                                          
        }
        return max_f;
    }
};
