class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;
        
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        return isPalindromeHelper(cleaned, 0);
    }

private:
    bool isPalindromeHelper(const string& s, int i) {
        if (i >= s.size() / 2)
            return true;

        if (s[i] != s[s.size() - i - 1])
            return false;

        return isPalindromeHelper(s, i + 1);
    }
};
