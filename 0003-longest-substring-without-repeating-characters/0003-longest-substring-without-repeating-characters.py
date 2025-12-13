class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index = {}
        max_len = 0
        start = 0 

        for i in range(len(s)):
            if s[i] in char_index and char_index[s[i]] >= start:
                start = char_index[s[i]] + 1

            char_index[s[i]] = i  
            max_len = max(max_len, i - start + 1)

        return max_len
