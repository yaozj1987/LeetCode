
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

// chen hao's solution
        int lengthOfLongestSubstring(string s) {
            const int MAX_CHARS = 256;
            int m[MAX_CHARS];
            memset(m, -1, sizeof(m));

            int maxLen = 0;
            // 记录上一次发生重复char的位置
            // 思想跟上面是类似的，只不过长度过长的时候，这个方法用到数组型的map，更快速
            int lastRepeatPos = -1;
            for(int i=0; i<s.size(); i++){
                // 更新lastRepactpos
                if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
                    lastRepeatPos = m[s[i]];
                }
                if ( i - lastRepeatPos > maxLen ){
                    maxLen = i - lastRepeatPos;
                }
                // 每个char都记录的是最新的这个char的index
                m[s[i]] = i;
             }
            return maxLen;
        }
